/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 23:45:29 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/17 18:07:57 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_a(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->ang.omega += ROTATE_1;
	go(e);
}

void		rotate_d(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->ang.omega -= ROTATE_1;
	go(e);
}

void		rotate_s(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->ang.alpha -= ROTATE_2;
	go(e);
}

void		rotate_w(t_env *e, t_img *img)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	e->ang.alpha += ROTATE_2;
	go(e);
}
