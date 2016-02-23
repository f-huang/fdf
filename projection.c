/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:08:36 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 11:10:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	n_iso(t_env *e, t_img *img)
{
	e->projection = 2;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	go(e);
}

void	n_ortho(t_env *e, t_img *img)
{
	e->projection = 1;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	go(e);
}
