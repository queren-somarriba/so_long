/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:19:54 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/11 11:42:44 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_anim	*init_anim(t_point p)
{
	t_anim	*anim;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	anim->frame = 0;
	anim->max_frame = 12;
	anim->p = p;
	return (anim);
}

void	init_frames(t_solong_data *data, t_img **t)
{
	t[0] = data->img->anim1;
	t[1] = data->img->anim2;
	t[2] = data->img->anim3;
	t[3] = data->img->anim4;
	t[4] = data->img->anim5;
	t[5] = data->img->anim6;
	t[6] = data->img->anim7;
	t[7] = data->img->anim8;
	t[8] = data->img->anim9;
	t[9] = data->img->anim10;
	t[10] = data->img->anim11;
	t[11] = data->img->exit2;
}

int	animate_exit(t_solong_data *data)
{
	t_img	*frames[12];

	if (!data->anim_mode)
		return (0);
	init_frames(data, frames);
	if (data->anim->frame < data->anim->max_frame)
	{
		img_to_win(data, frames[data->anim->frame],
			data->anim->p.y, data->anim->p.x);
		data->anim->frame++;
	}
	usleep(100 * 1000);
	if (data->anim->frame == data->anim->max_frame)
		return (data->anim_mode--, 0);
	return (1);
}
