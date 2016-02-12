/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:38:39 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/12 13:52:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	go_right(t_env *e, t_img *img)
{
	e->posx += SPACE;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, img->img, e->posx, e->posy);
}

void	go_left(t_env *e, t_img *img)
{
	e->posx -= SPACE;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, img->img, e->posx, e->posy);
}

void	go_up(t_env *e, t_img *img)
{
	e->posy -= SPACE;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, img->img, e->posx, e->posy);
}

void	go_down(t_env *e, t_img *img)
{
	e->posy += SPACE;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, img->img, e->posx, e->posy);
}
