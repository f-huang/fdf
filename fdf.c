/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/08 17:55:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_key(int keycode, t_env *env)
{
	printf("keycode :%i\n", keycode);
	if (env)
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
	int i = 0;
	while (i < 500)
	{
		y = a * i + b;
//		printf("X : %i -- Y : %i\n", x, y);
		img->addr[y * img->size_line + x] = 255;
		x += 4;
		i++;
	}
}

// BOUCLE
/*
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
			x++;
		}
		y++;
	}
}
*/
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
	if (r)
	line(&img, 0, 0, 30, 30);
	
	
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(env.mlx, env.win, img.img, 30, 40);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (1);
}
