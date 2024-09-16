/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:05:14 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/10 15:43:34 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (c == 'F' && data->life)
		img_to_win(data, data->img->player_f, i, j);
	if (c == 'W')
		img_to_win(data, data->img->wall2, i, j);
	if (c == 'B' && data->life)
		img_to_win(data, data->img->player_b, i, j);
	if (c == 'R' && data->life)
		img_to_win(data, data->img->player_r, i, j);
	if (c == 'L' && data->life)
		img_to_win(data, data->img->player_l, i, j);
	if (c == 'E')
		img_to_win(data, data->img->exit2, i, j);
	if (c == '1')
		img_to_win(data, data->img->enemy_r, i, j);
	if (c == '2')
		img_to_win(data, data->img->enemy_l, i, j);
	if (c == '3')
		img_to_win(data, data->img->enemy_f, i, j);
	if (c == '4')
		img_to_win(data, data->img->enemy_b, i, j);
	if (c == 'D')
		img_to_win(data, data->img->wall3, i, j);
}

int	img_to_win(t_solong_data *data,
			t_img *img, size_t i, size_t j)
{	
	return (mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, img, j * 64, i * 64));
}

int	put_count_on_window(t_solong_data *data)
{
	char	*str;

	str = ft_itoa(data->count_moves);
	replace_img(data, 'W', 0, 0);
	replace_img(data, 'W', 0, 1);
	if (!mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 32, 0x00FF0000, str))
		return (free(str), 1);
	return (free(str), 0);
}
