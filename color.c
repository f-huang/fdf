/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:10:43 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/22 17:13:02 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		switch_colors(t_env *e, t_img *img)
{
	static int	i = 0;

	i % 4 ? img->blue = 1 : (img->blue = 0);
	i % 2 ? img->green = 1 : (img->green = 0);
	i % 7 ? img->red = 1 : (img->red = 0);
	i++;
	if (i == 1)
		img->blue = 1;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	go(e);
}
