/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_and_close_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:14:09 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/10 19:28:46 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loose(t_solong_data *data)
{
	if (data->life)
	{
		data->map[data->player.y][data->player.x] = 'D';
		replace_img(data, 'D', data->player.y, data->player.x);
		ft_printf("You got caught by the patrol!! You loose...RIP\n");
	}
	data->life = 0;
}

int	error_map(char **map, int mode)
{
	ft_putstr_fd("Error\n", 2);
	if (mode == 0)
		return (ft_printf("So_long failed to open the Map file...\n"), 1);
	else if (mode == 1)
		return (ft_printf("Map file must be a .ber file!\n"), 1);
	else if (mode == 2)
	{
		if (check_start_exit_collectibles(map) == 1)
			return (ft_printf("Map must have one start position!\n"), 1);
		if (check_start_exit_collectibles(map) == 2)
			return (ft_printf("Map must have one exit!\n"), 1);
		if (check_start_exit_collectibles(map) == 3)
			return (ft_printf("This map miss some collectibles!\n"), 1);
		else if (check_map_char(map))
			return (ft_printf("Invalid character on map!\n"), 1);
		else if (check_border(map))
			return (ft_printf("Map must be closed by walls!\n"), 1);
		else if (check_rectangle(map))
			return (ft_printf("Map must be a rectangle!\n"), 1);
	}
	else if (mode == 3)
		return (ft_printf("Player can't reach the exit!\n"), 1);
	else if (mode == 4)
		return (ft_printf("Player can't reach all collectibles!\n", 1), 1);
	return (0);
}

static void	free_img_bonus(t_solong_data *data)
{
	if (data->img->enemy_f)
		mlx_destroy_image(data->mlx_ptr, data->img->enemy_f);
	if (data->img->enemy_b)
		mlx_destroy_image(data->mlx_ptr, data->img->enemy_b);
	if (data->img->enemy_l)
		mlx_destroy_image(data->mlx_ptr, data->img->enemy_l);
	if (data->img->enemy_r)
		mlx_destroy_image(data->mlx_ptr, data->img->enemy_r);
	if (data->img->anim1)
		mlx_destroy_image(data->mlx_ptr, data->img->anim1);
	if (data->img->anim2)
		mlx_destroy_image(data->mlx_ptr, data->img->anim2);
	if (data->img->anim3)
		mlx_destroy_image(data->mlx_ptr, data->img->anim3);
	if (data->img->anim4)
		mlx_destroy_image(data->mlx_ptr, data->img->anim4);
	if (data->img->anim5)
		mlx_destroy_image(data->mlx_ptr, data->img->anim5);
	if (data->img->anim6)
		mlx_destroy_image(data->mlx_ptr, data->img->anim6);
	if (data->img->anim7)
		mlx_destroy_image(data->mlx_ptr, data->img->anim7);
	if (data->img->anim8)
		mlx_destroy_image(data->mlx_ptr, data->img->anim8);
}

static void	free_img(t_solong_data *data)
{
	if (data->img->wall)
		mlx_destroy_image(data->mlx_ptr, data->img->wall);
	if (data->img->wall2)
		mlx_destroy_image(data->mlx_ptr, data->img->wall2);
	if (data->img->wall3)
		mlx_destroy_image(data->mlx_ptr, data->img->wall3);
	if (data->img->player_f)
		mlx_destroy_image(data->mlx_ptr, data->img->player_f);
	if (data->img->player_b)
		mlx_destroy_image(data->mlx_ptr, data->img->player_b);
	if (data->img->player_r)
		mlx_destroy_image(data->mlx_ptr, data->img->player_r);
	if (data->img->player_l)
		mlx_destroy_image(data->mlx_ptr, data->img->player_l);
	if (data->img->exit1)
		mlx_destroy_image(data->mlx_ptr, data->img->exit1);
	if (data->img->exit2)
		mlx_destroy_image(data->mlx_ptr, data->img->exit2);
	if (data->img->item)
		mlx_destroy_image(data->mlx_ptr, data->img->item);
	if (data->img->floor)
		mlx_destroy_image(data->mlx_ptr, data->img->floor);
	free_img_bonus(data);
	free(data->img);
}

int	close_window(t_solong_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img->anim9)
		mlx_destroy_image(data->mlx_ptr, data->img->anim9);
	if (data->img->anim10)
		mlx_destroy_image(data->mlx_ptr, data->img->anim10);
	if (data->img->anim11)
		mlx_destroy_image(data->mlx_ptr, data->img->anim11);
	free_img(data);
	ft_free_tab(data->map);
	free(data->enemy);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->anim);
	exit (0);
}
