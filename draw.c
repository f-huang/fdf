/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:18:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/16 23:40:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	x *= 4;
	img->addr[y * img->size_line + ++x] = color;//COLOR WRONG
	
//	printf("color ; %i\n", color);
}

void	line(t_env *e, t_coord *s)
{
	double		a;
	double		b;
	int			x;
	int			y;
	t_img		*img;

	img = &e->img;
//	printf("x1: %i\n", s->x1);
//	printf("y1: %i\n", s->x2);
//	printf("x2: %i\n", s->y1);
//	printf("y2: %i\n", s->y2);
	a = 0;
	if (s->x2 != s->x1)
		a = (double)(s->y2 - s->y1) / (double)(s->x2 - s->x1);
	b = (double)((s->y1 - a * s->x1));
	x = s->x1;
	while (x < s->x2)
	{
		y = a * x + b;
		put_pixel_img(img, x, y, 255);
		x++;
	}
}

void	line_ver(t_env *e, int x, int y)
{
	int		i;
	t_img	*img;

	img = &e->img;
	i = 0;
	while (i < SPACE)
	{
		put_pixel_img(img, x, y, 255);
		y++;
		i++;
	}
}
