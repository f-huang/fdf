/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:23:35 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/22 23:30:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_key(t_env *e, t_img *img)
{
	(void)img;
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_SUCCESS);
}

int		keys(int kc, t_env *e)
{

	printf("kc : %i\n", kc);
	static void	(*p[127])(t_env *e, t_img *img);

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
	p[KEY_SPACE] = switch_colors;



	if (kc == ESC || kc == ARROW_LEFT || kc == ARROW_RIGHT || kc == ARROW_UP\
			|| kc == ARROW_DOWN || kc == BRACKET_1 || kc == BRACKET_2 ||\
			kc == COMA || kc == DOT || kc == KEY_W || kc == KEY_S ||\
			kc == KEY_A || kc == KEY_D || kc == KEY_SPACE)
	
	(*p[kc])(e, &e->img);
	return (0);
}
