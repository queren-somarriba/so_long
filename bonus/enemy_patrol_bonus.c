/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:31:13 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/06 19:30:58 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_mouvment(t_solong_data *data, size_t count, t_point p, char a)
{
	t_point	p1;

	p1 = data->enemy[count];
	if (data->map[p.x][p.y] == 'P')
		loose(data);
	else if (data->map[p.x][p.y] == '0')
	{
		data->map[p1.x][p1.y] = '0';
		data->map[p.x][p.y] = 'X';
		data->enemy[count] = p;
		replace_img(data, '0', p1.x, p1.y);
		replace_img(data, a, p.x, p.y);
	}
	else
	{
		replace_img(data, '3', p1.x, p1.y);
		if (data->dir == 0 || data->dir == 1 || data->dir == 2)
			data->dir++;
		else if (data->dir == 3)
			data->dir = 0;
	}
}	

static void	make_patrol_move(t_solong_data *data, size_t count)
{
	t_point	p;

	p.x = data->enemy[count].x;
	p.y = data->enemy[count].y;
	if (data->dir == 0)
	{
		p.y++;
		enemy_mouvment(data, count, p, '1');
	}
	else if (data->dir == 1)
	{
		p.x++;
		enemy_mouvment(data, count, p, '3');
	}
	else if (data->dir == 2)
	{
		p.y--;
		enemy_mouvment(data, count, p, '2');
	}
	else if (data->dir == 3)
	{
		p.x--;
		enemy_mouvment(data, count, p, '4');
	}
}

size_t	enemy_count(t_solong_data *data)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = -1;
	count = 0;
	while (++i < data->map_len)
	{
		j = -1;
		while (++j < data->map_wid)
		{
			if (data->map[i][j] == 'X')
				count++;
		}
	}
	return (count);
}

t_point	*set_enemy_p(t_solong_data *data)
{
	t_point	*tab;
	size_t	i;
	size_t	j;
	size_t	count;

	i = -1;
	count = 0;
	tab = malloc(sizeof(t_point) * (data->enemy_count + 1));
	if (!tab)
		close_window(data);
	while (++i < data->map_len && count < data->enemy_count)
	{
		j = -1;
		while (++j < data->map_wid && count < data->enemy_count)
		{
			if (data->map[i][j] == 'X')
			{
				tab[count].x = i;
				tab[count].y = j;
				count++;
			}
		}
	}
	return (tab);
}

void	move_patrol(t_solong_data *data)
{
	size_t	count;

	count = -1;
	while (++count < data->enemy_count)
		make_patrol_move(data, count);
}
