/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:23:35 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/17 17:01:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_key(t_env *e, t_img *img)
{
	(void)img;
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_SUCCESS);
}

int		keys(int keycode, t_env *e)
{

	printf("keycode : %i\n", keycode);
	void	(*p[127])(t_env *e, t_img *img);

	p[ESC] = exit_key;
	p[ARROW_LEFT] = go_left;
	p[ARROW_RIGHT] = go_right;
	p[ARROW_UP] = go_up;
	p[ARROW_DOWN] = go_down;
	p[COMA] = zoom_in;
	p[DOT] = zoom_out;
	p[BRACKET_1] = relief_plus;
	p[BRACKET_2] = relief_minus;
	p[KEY_W] = rotate_w;
	p[KEY_S] = rotate_s;
	p[KEY_A] = rotate_a;
	p[KEY_D] = rotate_d;



	if (keycode == ESC || keycode == ARROW_LEFT || keycode == ARROW_RIGHT ||\
			keycode == ARROW_UP || keycode == ARROW_DOWN || keycode == PLUS ||\
			keycode == MINUS || keycode == BRACKET_1 || keycode == BRACKET_2 ||\
			keycode == COMA || keycode == DOT || keycode == KEY_W || keycode ==\
			KEY_S || keycode == KEY_A || keycode == KEY_D)
	
	(*p[keycode])(e, &e->img);
	return (0);
}
