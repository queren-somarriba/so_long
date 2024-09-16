/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_put_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:26 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/06 19:34:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_solong_data *data)
{
	data->img->wall = safe_xpm_file_to_img(data, "xpm/wall/wall.xpm");
	data->img->wall2 = safe_xpm_file_to_img(data, "xpm/wall/wall2.xpm");
	data->img->exit1 = safe_xpm_file_to_img(data, "xpm/exit/exit1.xpm");
	data->img->exit2 = safe_xpm_file_to_img(data, "xpm/exit/exit2.xpm");
	data->img->floor = safe_xpm_file_to_img(data, "xpm/floor/floor.xpm");
	data->img->item = safe_xpm_file_to_img(data, "xpm/items/banana.xpm");
	data->img->player_f = safe_xpm_file_to_img(data, "xpm/player/front.xpm");
	data->img->player_b = safe_xpm_file_to_img(data, "xpm/player/back.xpm");
	data->img->player_r = safe_xpm_file_to_img(data, "xpm/player/right.xpm");
	data->img->player_l = safe_xpm_file_to_img(data, "xpm/player/left.xpm");
}

static void	put_top_images_on_window(t_solong_data *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < data->map_len)
	{
		j = -1;
		while (++j < data->map_wid)
		{
			if (i == 0 || i == data->map_len - 1 || j == 0
				|| j == data->map_wid - 1)
				img_to_win(data, data->img->wall2, i, j);
			else if (data->map[i][j] == '1')
				img_to_win(data, data->img->wall, i, j);
			if (data->map[i][j] == 'C')
				img_to_win(data, data->img->item, i, j);
			else if (data->map[i][j] == 'E')
				img_to_win(data, data->img->exit1, i, j);
			if (data->map[i][j] == 'P')
				img_to_win(data, data->img->player_f, i, j);
		}
	}
}

int	put_map_on_window(t_solong_data *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < data->map_len)
	{
		j = -1;
		while (++j < data->map_wid)
			img_to_win(data, data->img->floor, i, j);
	}
	put_top_images_on_window(data);
	return (0);
}
