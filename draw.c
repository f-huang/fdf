/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:18:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 19:01:42 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y)
{
	x *= 4;
//	printf("Y ::::: %i\n", y);
//	printf("H ::::: %i\n", HEIGHT);
	if (y >= 0 && y < HEIGHT && x >= 0 && x < img->size_line)
	{
		if (img->blue)
			img->addr[y * img->size_line + x] = 255;
		x++;
//		printf("%i\n", img->green);
//	printf("%u\n", x);
//	printf("%u\n", y);
		if (img->green)
			img->addr[y * img->size_line + x] = 255;
		x++;
		if (img->red)
			img->addr[y * img->size_line + x] = 255;
	}
}

void	line(t_env *e, t_coord *s)
{
	int				i;
	t_line_tools	lt;

	abs(s->x2 - s->x1) >= abs(s->y2 - s->y1) ?\
		(lt.longueur = abs(s->x2 - s->x1)) : (lt.longueur = abs(s->y2 - s->y1));
	if (lt.longueur)
	{
		lt.dx = (s->x2 - s->x1) / lt.longueur;
		lt.dy = (s->y2 - s->y1) / lt.longueur;
	}
	lt.x = s->x1;
	lt.y = s->y1;
	i = 0;
	while (i < lt.longueur)
	{
//		printf("BEF : %f et %f\n", lt.x, lt.y);
		put_pixel_img(&e->img, lt.x, lt.y);
//		printf("af\n");
		lt.x += lt.dx;
		lt.y += lt.dy;
		i++;
	}
}
