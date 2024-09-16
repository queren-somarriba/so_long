/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:29:42 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/09 12:37:04 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_rectangle(char **map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	len--;
	while (map[++i])
	{
		if (i == len && ft_strlen(map[i]) == ft_strlen(map[i -1]) - 1)
			return (0);
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (1);
	}
	return (0);
}

size_t	count_char(char **map, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				count++;
		}
	}
	return (count);
}

int	check_map_char(char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map[i][j] == '0' || map[i][j] == '1'
				|| map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'X'
				|| map[i][j] == 'P' || map[i][j] == '\n'))
				return (1);
		}
	}
	return (0);
}

int	check_start_exit_collectibles(char **map)
{
	if (count_char(map, 'P') != 1)
		return (1);
	if (count_char(map, 'E') != 1)
		return (2);
	if (!count_char(map, 'C'))
		return (3);
	return (0);
}

int	check_border(char **map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	len = ft_strlen(map[0]);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (map[i][0] != '1' || map[i][j - 2] != '1')
			return (1);
	}
	j = -1;
	while (++j < len - 1)
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			return (1);
	}
	return (0);
}
