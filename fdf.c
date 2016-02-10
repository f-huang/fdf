/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/10 18:19:30 by fhuang           ###   ########.fr       */
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
	t_coord c1;
	t_coord c2;

	y = 0;
	while (y < r->n_line)
	{
		x = 0;
		while (x < r->len_line[y])
		{
			c1.x = x;
			c1.y = y;
			c1.z = r->data[y][x];
			c2.x = x + 1;
			c2.y = y;
			c2.z = r->data[y][x + 1];
			x++;
		}
		y++;
	}
}




void	draw_line(t_coord *c1, t_coord *c2)
{
	//if (x1->z == z2->z) //TRAIT VERT OU HOR
		//VERT SI x1-> x == x2-> x
		//HOR SI x1->y == x2->y
		//

	//SINON
		//x1->z < x2->z ----------- TRAIT / ------------ y--
		//" ""  > " " "" ------------ TRAIT \---------  y++

	if (c1->z == c2->z)
	{
		if (c1->x == c2->x)
			//Trait VERT
		else if (c1->y == c2->y)
			//Trait HOR
	}
	else



}
*/










int		init_env(t_read *r)
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
	if (r)
		line(&img, 0,0, 2, 1);
	
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(e.mlx, e.win, img.img, 30, 40);
	mlx_key_hook(e.win, exit_key, &e);
	mlx_loop(e.mlx);
	return (1);
}
