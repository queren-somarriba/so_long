/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:11:43 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/06 19:15:12 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_move(t_solong_data data, int key, char c)
{
	t_point	p;

	p.y = data.player.y;
	p.x = data.player.x;
	if (key != XK_w && key != XK_s && key != XK_a
		&& key != XK_d && key != XK_Escape)
		return (1);
	if (key == XK_w && data.map[p.y -1][p.x] == c)
		return (1);
	if (key == XK_s && data.map[p.y + 1][p.x] == c)
		return (1);
	if (key == XK_a && data.map[p.y][p.x - 1] == c)
		return (1);
	if (key == XK_d && data.map[p.y][p.x + 1] == c)
		return (1);
	return (0);
}

static void	make_player_move(t_solong_data *data, int key, size_t x, size_t y)
{
	img_to_win(data, data->img->floor, y, x);
	if (key == XK_w)
	{
		data->player.y--;
		replace_img(data, 'B', y - 1, x);
	}
	if (key == XK_s)
	{
		data->player.y++;
		replace_img(data, 'F', y + 1, x);
	}
	if (key == XK_a)
	{
		data->player.x--;
		replace_img(data, 'L', y, x - 1);
	}
	if (key == XK_d)
	{
		data->player.x++;
		replace_img(data, 'R', y, x + 1);
	}
}

static void	check_items(t_solong_data *data)
{
	t_point	p;

	p = find_char(data->map, 'E');
	data->items--;
	if (!data->items)
		replace_img(data, 'E', p.y, p.x);
}

int	move_player(t_solong_data *data, int key)
{
	if (check_move(*data, key, '1')
		|| (check_move(*data, key, 'E') && data->items != 0))
		return (-1);
	else
	{
		data->map[data->player.y][data->player.x] = '0';
		ft_printf("Player move count : %d\n", ++data->count_moves);
		make_player_move(data, key, data->player.x, data->player.y);
		if (data->map[data->player.y][data->player.x] == 'E'
			&& data->items == 0)
			return (ft_printf("Congratulation, you win !!\n"), 1);
		if (data->map[data->player.y][data->player.x] == 'C')
			check_items(data);
		if (data->map[data->player.y][data->player.x] != 'E')
			data->map[data->player.y][data->player.x] = 'P';
	}
	return (0);
}

int	handle_keypress(int keysym, t_solong_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else
	{
		if (move_player(data, keysym) == 1)
			close_window(data);
	}
	return (0);
}
