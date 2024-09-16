/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_and_quit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:14:09 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/06 17:27:00 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_error_img(void *img)
{
	if (!img)
		return (ft_printf("Error converting xpm file to image!\n"), 1);
	return (0);
}

void	free_img(t_solong_data *data)
{
	if (data->img->wall)
		mlx_destroy_image(data->mlx_ptr, data->img->wall);
	if (data->img->wall2)
		mlx_destroy_image(data->mlx_ptr, data->img->wall2);
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
	free(data->img);
}

int	close_window(t_solong_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_img(data);
	ft_free_tab(data->map);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
