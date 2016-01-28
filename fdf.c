/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/28 17:12:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_key(int keycode, t_env *env)
{
	if (env)
		if (keycode == 53)
			exit(0);
	printf("keycode :%i\n", keycode);
	return (0);
}

void	draw(t_img *img, int x1, int x2, int y)
{
	int		i;

	if (x1 == x2)
	{
		i = 0;
		while (i < SPACE)
		{
			img->addr[y * img->size_line + x1] = 255;
			i++;
			x1 += 4;
		}
	}
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
	int i = 0;
	while (i < SPACE)
	{
		y = a * i + b;
//		printf("X : %i -- Y : %i\n", x, y);
		img->addr[y * img-> size_line + x] = 255;
		x += 4;
		i++;
	}
}

void	horiz_line(t_img *img, int x1, int x2, int y)
{
	int		i;

	i = 0;
	while (i < SPACE)
	{
		if (x1 <= x2)
		{
			line(img, x1, x2, y, y - x2);
		}
		else if (x1 > x2)
		{
			line(img, x1, x2, y, y + x2);
		}
		i++;
	}
}


void	get_data(t_read *r, t_img *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < r->n_line)
	{
		x = 0;
		while (x < r->len_line[y])
		{
			horiz_line(img, r->data[y][x], r->data[y][x + 1], y);
			x++;
		}
		y++;
	}
}

int		init_env(t_read *r)
{
	t_img		img;
	t_env		env;

	if (!(env.mlx = mlx_init()))
		return (0);
	if (!(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "MLX")))
		return (0);
	if (!(img.img = mlx_new_image(env.mlx, WIDTH, HEIGHT)))
		return (0);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.size_line, &img.endian);
	
	//////////////////////////////////////////////////////////////////////////
	if (r->data == NULL)	
		printf("null\n");
	if (r->data[0] == NULL)
		printf("IO\n");
//	line(&img, 5, 2, 6, 30);
	get_data(r, &img);
//	draw(&img, 0, 0 ,5);
	
	
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(env.mlx, env.win, img.img, 30, 40);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (1);
}
