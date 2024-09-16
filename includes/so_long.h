/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:29:48 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/11 11:48:53 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}		t_point;

typedef struct s_img
{
	void	*wall;
	void	*wall2;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*exit1;
	void	*exit2;
	void	*item;
	void	*floor;

}		t_img;

typedef struct s_solong_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_point	player;
	size_t	items;
	size_t	count_moves;
	char	**map;
	size_t	map_len;
	size_t	map_wid;
	int		img_len;
	int		img_wid;

}		t_solong_data;

size_t			count_lines(char *file);

size_t			count_char(char **map, char c);

t_point			find_char(char **map, char c);

char			**get_map(char *file);

int				check_border(char **map);

int				check_start_exit_collectibles(char **map);

int				check_rectangle(char **map);

int				check_map(char *file);

int				check_map_char(char **map);

int				extention_checker(char *str);

int				error_map(char **map, int mode);

int				move_player(t_solong_data *data, int keysym);

int				handle_keypress(int keysym, t_solong_data *data);

int				close_window(t_solong_data *data);

void			get_img(t_solong_data *data);

int				put_map_on_window(t_solong_data *data);

void			*safe_xpm_file_to_img(t_solong_data *data, char *file);

int				img_to_win(t_solong_data *data, t_img *img, size_t i, size_t j);

void			replace_img(t_solong_data *data, char c, size_t i, size_t j);

#endif
