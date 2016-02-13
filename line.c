/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:18:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/13 20:15:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	x *= 4;
	img->addr[y * img->size_line + ++x] = color;//COLOR WRONG
	
//	printf("color ; %i\n", color);


	if (color != 255)
	img->addr[y * img->size_line + ++x] = color; //COLOR WRONG
}

void	line(t_env *e, int x1, int y1, int x2, int y2)
{
	double		a;
	double		b;
	double		x;
	int			y;
	t_img		*img;

	img = &e->img;
	a = 0;
	if (x2 != x1)
		a = (double)(y2 - y1) / (double)(x2 - x1);
	b = (double)((y1 - a * x1));
	x = x1;
	while (x < x2)
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
