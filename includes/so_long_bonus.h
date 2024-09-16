/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:29:28 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/11 11:50:12 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}		t_point;

typedef struct s_img
{
	void	*wall;
	void	*wall2;
	void	*wall3;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*exit1;
	void	*exit2;
	void	*item;
	void	*floor;
	void	*enemy_f;
	void	*enemy_b;
	void	*enemy_r;
	void	*enemy_l;
	void	*anim1;
	void	*anim2;
	void	*anim3;
	void	*anim4;
	void	*anim5;
	void	*anim6;
	void	*anim7;
	void	*anim8;
	void	*anim9;
	void	*anim10;
	void	*anim11;
}		t_img;

typedef struct s_anim
{
	int		frame;
	int		max_frame;
	t_point	p;
}	t_anim;

typedef struct s_solong_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_point	player;
	int		life;
	size_t	items;
	size_t	count_moves;
	char	**map;
	size_t	map_len;
	size_t	map_wid;
	int		img_len;
	int		img_wid;
	size_t	enemy_count;
	int		dir;
	int		anim_mode;
	t_anim	*anim;
	t_point	*enemy;

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

int				close_window(t_solong_data *data);

void			get_img(t_solong_data *data);

void			get_img_bonus(t_solong_data *data);

int				put_map_on_window(t_solong_data *data);

void			*safe_xpm_file_to_img(t_solong_data *data, char *file);

int				img_to_win(t_solong_data *data, t_img *img, size_t i, size_t j);

void			replace_img(t_solong_data *data, char c, size_t i, size_t j);

void			loose(t_solong_data *data);

void			move_patrol(t_solong_data *data);

int				put_count_on_window(t_solong_data *data);

int				check_items(t_solong_data *data);

size_t			enemy_count(t_solong_data *data);

t_point			*set_enemy_p(t_solong_data *data);

int				animate_exit(t_solong_data *data);

t_anim			*init_anim(t_point p);

#endif
