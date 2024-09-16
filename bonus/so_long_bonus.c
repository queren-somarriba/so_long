/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:46:39 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/10 17:19:13 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_img	*init_img(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->wall = NULL;
	img->player_f = NULL;
	img->player_b = NULL;
	img->player_r = NULL;
	img->player_l = NULL;
	img->exit1 = NULL;
	img->exit2 = NULL;
	img->item = NULL;
	img->floor = NULL;
	img->enemy_f = NULL;
	img->enemy_b = NULL;
	img->enemy_r = NULL;
	img->enemy_l = NULL;
	return (img);
}

static t_solong_data	init_solong(char *file)
{
	t_solong_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit(1);
	data.map = get_map(file);
	data.player = find_char(data.map, 'P');
	data.items = count_char(data.map, 'C');
	data.count_moves = 0;
	data.life = 1;
	data.map_len = count_lines(file);
	data.map_wid = ft_strlen(data.map[0]) - 1;
	data.enemy_count = enemy_count(&data);
	data.enemy = set_enemy_p(&data);
	data.dir = 0;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_wid * 64,
			data.map_len * 64, "So_Long_Bonus");
	if (data.win_ptr == NULL)
		free(data.win_ptr);
	data.img = init_img();
	get_img(&data);
	data.anim_mode = 1;
	data.anim = init_anim(find_char(data.map, 'E'));
	return (data);
}

static int	handle_keypress(int keysym, t_solong_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else
	{
		if (data->life)
		{
			if (move_player(data, keysym) == 1)
				close_window(data);
		}
		move_patrol(data);
		put_count_on_window(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong_data	data;

	if (argc == 2)
	{
		if (check_map(argv[1]))
			return (1);
		data = init_solong(argv[1]);
		if (put_map_on_window(&data))
			return (ft_printf("Error put_img_on_window\n"), 1);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.win_ptr, DestroyNotify, 1L << 17, &close_window, &data);
		mlx_loop(data.mlx_ptr);
		return (0);
	}
	return (1);
}
