/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/11 12:59:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_key(int keycode, t_env *e)
{
	printf("keycode :%i\n", keycode);
	if (e)
		if (keycode == 53)
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
	x = 0;
	while (x < 20)
	{
		y = a * x + b;
		put_pixel_img(img, x, y, 255);
		x++;
		//		printf("X : %i -- Y : %i\n", x, y);
	}
}

void	dot_at_dot(t_read *r, t_img *img)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		color;

	y = 500;
	j = 0;
	color = 255;
	while (j < r->n_line)
	{
		i = 0;
		x = 100;
		while (i < r->len_line[j])
		{
			if (r->data[j][i] != 0)
				color = 100;
			y = y - r->data[j][i];
			put_pixel_img(img, x, y, color);
			line(img, i, j, x, y);
			x += 10;
			i++;
		}
		y += 10;
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
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);

	//////////////////////////////////////////////////////////////////////////
	/*
	   for (int y = 0; y < 500 ; y++)
	   for (int x = 0; x < 500 ; x++ )
	   put_pixel_img(&img, x, y, 255);
	   */
	dot_at_dot(r, &img);
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(e.mlx, e.win, img.img, 30, 40);
	mlx_key_hook(e.win, exit_key, &e);
	mlx_loop(e.mlx);
	return (1);
}
