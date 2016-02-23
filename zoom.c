/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:10:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 10:42:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_in(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->space += ZOOM;
	go(e);
}

void		zoom_out(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->space -= ZOOM;
	if (e->space <= 0)
		e->space = 1;
	go(e);
}
