/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:18:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/20 18:29:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y)
{
	x *= 4;
//	printf("X : %i\n", x);
//	printf("SL : %i\n", img->size_line);
//	printf("Y : %i\n", y);
	if (y >= 0 && y <= HEIGHT && x >= 0 && x < img->size_line)
	{
		if (img->blue)
			img->addr[y * img->size_line + x] = 255;//COLOR WRONG
			x++;
		if (img->green)
			img->addr[y * img->size_line + x] = 255;//COLOR WRONG
			x++;
		if (img->red)
			img->addr[y * img->size_line + x] = 255;//COLOR WRONG
	}
//	printf("color ; %i\n", color);
}

void	line(t_env *e, t_coord *s)
{
	double		dx;
	double		dy;
	double			x;
	double			y;
	double		longueur;

	abs(s->x2 - s->x1) >= abs(s->y2 - s->y1) ? (longueur = abs(s->x2 - s->x1)) : (longueur = abs(s->y2 - s->y1));
	if (longueur)
	{
		dx = (s->x2 - s->x1) / longueur;
		dy = (s->y2 - s->y1) / longueur;
	}
	x = s->x1;
	y = s->y1;
	int		i = 0;
	while (i < longueur)
	{
		put_pixel_img(&e->img, x, y);
//		printf("XX : %f\n", x);
//		printf("YY : %f\n", y);
		x += dx;
		y += dy;
		i++;
	}
}
