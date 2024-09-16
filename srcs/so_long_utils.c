/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:05:14 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/11 11:50:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_char(char **map, char c)
{
	t_point	p;
	size_t	i;
	size_t	j;

	p.x = 0;
	p.y = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				p.x = j;
				p.y = i;
				return (p);
			}
		}
	}
	return (p);
}

void	*safe_xpm_file_to_img(t_solong_data *data, char *file)
{
	void	*img;

	img = NULL;
	img = mlx_xpm_file_to_image(data->mlx_ptr,
			file, &data->img_wid, &data->img_len);
	if (!img)
	{
		ft_printf("Error converting xpm file to image!\n");
		close_window(data);
	}
	return (img);
}

void	replace_img(t_solong_data *data, char c, size_t i, size_t j)
{
	img_to_win(data, data->img->floor, i, j);
	if (c == 'F')
		img_to_win(data, data->img->player_f, i, j);
	if (c == 'B')
		img_to_win(data, data->img->player_b, i, j);
	if (c == 'R')
		img_to_win(data, data->img->player_r, i, j);
	if (c == 'L')
		img_to_win(data, data->img->player_l, i, j);
	if (c == 'E')
		img_to_win(data, data->img->exit2, i, j);
}

int	img_to_win(t_solong_data *data,
			t_img *img, size_t i, size_t j)
{	
	return (mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, img, j * 64, i * 64));
}

int	extention_checker(char *str)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	s = ft_substr(str, len - 4, 4);
	if (!s)
		return (1);
	if (len < 4)
		return (1);
	if (!ft_strncmp(s, ".ber", 4))
		return (free(s), 1);
	else
		return (free(s), 0);
}
