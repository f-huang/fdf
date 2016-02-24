/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:10:43 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/24 11:32:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		switch_colors(t_env *e, t_img *img)
{
	static int	i = 0;

	img->blue = i % 2 ? 1 : 0;
	img->green = i % 5 ? 1 : 0;
	img->red = i % 6 ? 1 : 0;
	i++;
	if (i == 1)
		img->blue = 1;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	go(e);
}
