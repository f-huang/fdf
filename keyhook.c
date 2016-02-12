/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:23:35 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/12 19:50:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_key(t_env *e, t_img *img)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_SUCCESS);
}

int		keys(int keycode, t_env *e)
{

	printf("keycode : %i\n", keycode);
	void	(*p[99999])(t_env *e, t_img *img);

	p[ESC] = exit_key;
	p[ARROW_LEFT] = go_left;
	p[ARROW_RIGHT] = go_right;
	p[ARROW_UP] = go_up;
	p[ARROW_DOWN] = go_down;
	p[PLUS] = zoom_in;
	p[MINUS] = zoom_out;
	p[BRACKET_1] = relief_plus;

	if (keycode == ESC || keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_UP || keycode == ARROW_DOWN || keycode == PLUS || keycode == MINUS || keycode == BRACKET_1)
	(*p[keycode])(e, &e->img);
	return (0);
}
