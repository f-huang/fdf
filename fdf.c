/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/12 13:52:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_key(int keycode, t_env *e)
{
	printf("keycode :%i\n", keycode);
	if (e)
		if (keycode == ESC)
			exit(0);
	return (0);
}

void	line(t_img *img, int x1, int y1, int x2, int y2)
{
	double		a;
	double		b;
	int			x;
	int			y;

	//	if (y2 == y1)
	//		ver_line(img, x1, x2);
	a = 0;
	if (x2 != x1)
		a = (double)(y2 - y1) / (double)(x2 - x1);
	b = (double)((y1 - a * x1));
	//	printf (" y = %fx + %f\n" ,a , b);
	x = x1;
	while (x < x2)
	{
		y = a * x + b;
		put_pixel_img(img, x, y, 255);
		x++;
		//		printf("X : %i -- Y : %i\n", x, y);
	}
}

void	line_ver(t_img *img, int x, int y)
{
	int		i;

	i = 0;
	while (i< SPACE)
	{
		put_pixel_img(img, x, y, 255);
		y++;
		i++;
	}
}

void	dot_at_dot(t_read *r, t_img *img)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = 30;
	j = 0;
	while (j < r->n_line)
	{
		i = 0;
		x = 40;
		while (i < r->len_line[j])
		{
			if (i + 1 < r->len_line[j])
			{
				put_pixel_img(img, x, y, img->color);
				line(img, x, y - r->data[j][i], x + SPACE, y-r->data[j][i + 1]);
			}
			if (j + 1 < r->n_line)
					line_ver(img, x, y);
			x += SPACE;
			i++;
		}
		y += SPACE;
		j++;
	}
}

int		start_env(t_read *r)
{
	t_img		img;
	t_env		e;

	if (!(e.mlx = mlx_init()))
		return (0);
	if (!(e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "MLX")))
		return (0);
	if (!(img.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
		return (0);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.size_line, &img.endian);

	//////////////////////////////////////////////////////////////////////////
	/*
	   for (int y = 0; y < 500 ; y++)
	   for (int x = 0; x < 500 ; x++ )
	   put_pixel_img(&img, x, y, 255);
	   */
	dot_at_dot(r, &img);
	//////////////////////////////////////////////////////////////////////////
	e.posx = 0;
	e.posy = 0;
	mlx_put_image_to_window(e.mlx, e.win, img.img, e.posx, e.posy);
	mlx_key_hook(e.win, exit_key, &e);
	mlx_loop(e.mlx);
	return (1);
}
