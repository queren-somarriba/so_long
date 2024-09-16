/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:45:52 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/10 17:02:58 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	count_lines(char *file)
{
	int		fd;
	char	*line;
	size_t	count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), count);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	size_t	i;

	i = -1;
	map = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!map)
		map = (char **)malloc(sizeof(char *) * (count_lines(file) + 1));
	if (!map)
		return (free(line), close(fd), NULL);
	while (line)
	{
		map[++i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[++i] = NULL;
	if (i < 2)
		return (ft_free_tab(map), close(fd), NULL);
	return (close(fd), map);
}

static int	search_path(char **map, size_t i, size_t j)
{
	if (map[i][j] == 'P')
		return (0);
	if (map[i][j] == '1' || map[i][j] == 'X')
		return (-1);
	map[i][j] = 'X';
	if (!search_path(map, i + 1, j))
		return (0);
	if (!search_path(map, i, j + 1))
		return (0);
	if (!search_path(map, i - 1, j))
		return (0);
	if (!search_path(map, i, j - 1))
		return (0);
	return (-1);
}

static int	check_reachable(char **map, char *file, char c)
{
	size_t	i;
	size_t	j;
	char	**tmp;

	i = -1;
	tmp = NULL;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				if (tmp)
					ft_free_tab(tmp);
				tmp = get_map(file);
				if (search_path(tmp, i, j))
					return (ft_free_tab(tmp), 1);
			}
		}
	}
	return (ft_free_tab(tmp), 0);
}

int	check_map(char *file)
{
	char	**tmp;

	tmp = get_map(file);
	if (open(file, O_RDONLY) == -1)
		return (error_map(tmp, 0), 1);
	if (tmp == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_printf("File is not a map!");
		return (1);
	}
	if (!extention_checker(file))
		return (error_map(tmp, 1), ft_free_tab(tmp), 1);
	if (check_start_exit_collectibles(tmp) || check_map_char(tmp)
		|| check_border(tmp) || check_rectangle(tmp))
		return (error_map(tmp, 2), ft_free_tab(tmp), 1);
	if (check_reachable(tmp, file, 'E'))
		return (error_map(tmp, 3), ft_free_tab(tmp), 1);
	ft_free_tab(tmp);
	tmp = get_map(file);
	if (check_reachable(tmp, file, 'C'))
		return (error_map(tmp, 4), ft_free_tab(tmp), 1);
	return (ft_free_tab(tmp), 0);
}
