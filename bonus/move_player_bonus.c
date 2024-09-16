/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:11:43 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/11 11:39:49 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	check_enemy(t_solong_data *data, int mode)
{
	t_point	p;

	p = data->player;
	if (data->map[p.y][p.x] == 'X' && mode == 0)
	{
		replace_img(data, 'D', data->player.y++, data->player.x);
		loose(data);
	}
	if (data->map[p.y][p.x] == 'X' && mode == 1)
	{
		replace_img(data, 'D', data->player.y--, data->player.x);
		loose(data);
	}
	if (data->map[p.y][p.x] == 'X' && mode == 2)
	{
		replace_img(data, 'D', data->player.y, data->player.x++);
		loose(data);
	}
	if (data->map[p.y][p.x] == 'X' && mode == 3)
	{
		replace_img(data, 'D', data->player.y, data->player.x--);
		loose(data);
	}
}

static void	make_player_move(t_solong_data *data, int key, size_t x, size_t y)
{
	img_to_win(data, data->img->floor, y, x);
	if (key == XK_w)
	{
		data->player.y--;
		check_enemy(data, 0);
		replace_img(data, 'B', y - 1, x);
	}
	if (key == XK_s)
	{
		data->player.y++;
		check_enemy(data, 1);
		replace_img(data, 'F', y + 1, x);
	}
	if (key == XK_a)
	{
		data->player.x--;
		check_enemy(data, 2);
		replace_img(data, 'L', y, x - 1);
	}
	if (key == XK_d)
	{
		data->player.x++;
		check_enemy(data, 3);
		replace_img(data, 'R', y, x + 1);
	}
}

int	check_items(t_solong_data *data)
{
	data->items--;
	if (!data->items)
	{
		mlx_loop_hook(data->mlx_ptr, (int (*)(void *))animate_exit, data);
		return (0);
	}
	return (1);
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
		if (data->life)
		{
			if (data->map[data->player.y][data->player.x] == 'E'
				&& data->items == 0)
				return (ft_printf("Congratulation, you win !!\n"), 1);
			if (data->map[data->player.y][data->player.x] == 'C')
				check_items(data);
			if (data->map[data->player.y][data->player.x] != 'E'
					&& data->map[data->player.y][data->player.x] != 'X')
				data->map[data->player.y][data->player.x] = 'P';
		}
	}
	return (0);
}
