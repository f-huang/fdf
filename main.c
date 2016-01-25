/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:59:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/25 13:25:28 by fhuang           ###   ########.fr       */
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

void	ver_line(t_img *img, int x1, int x2)
{
	int		y;

	y = 0;
	while (y < x2)
	{
		img->addr[y * img->size_line + x1] = 255;
		y++;
	}
}

void	line(t_img *img, int x1, int y1, int x2, int y2)
{
	double		a;
	double		b;
	int			x;
	int			y;

	if (y2 == y1)
		ver_line(img, x1, x2);
	a = 0;
	if (x2 != x1)
		a = (double)(y2 - y1) / (double)(x2 - x1);
	b = (double)((y1 - a * x1));
	printf (" y = %fx + %f\n" ,a , b);
	x = 0;
	int i = 0;
	while (i < img->size_line)
	{
		y = a * i + b;
		img->addr[y * img-> size_line + x] = 255;
		x += 4;
		i++;
	}
}

void	line_x(t_img *img, int x1, int x2, int y)
{
//	if (x2 == x1)
//		hor_line();
//	else
//	{
		if (x1 < x2)
			line(img, x1, y, x2, y - x1);
		else
			line(img, x1, y, x2, y + x1);
//	}
}

void	line_y(t_img *img, int y1, int y2, int x)
{
	if (y1 == y2)
		ver_line(img, y1, y2);
	else
	{
		if (y1 < y2)
			line(img, x, y1, x - y1, y2);
		else
			line(img, x, y1, x + y1, y2);
	}
}

void	grid(t_img *img, t_read *r)
{
	int		x;
	int		y;

	y = 0;
	while (y < r->n_line)
	{
		x = 0;
		while (x < r->len_line[y])
		{
			if (x + 1 < r->len_line[y])
				line_x(img, r->data[y][x],r->data[y][x + 1], y );
			if (y + 1 < r->n_line)
				line_x(img, r->data[y][x],r->data[y + 1][x], x );
			x++;
		}
		y++;
	}

}


int		main(int ac, char **av)
{
	t_env	env;
	t_img	img;
	t_read	r;

	if (!(env.mlx = mlx_init()))
		return (-1);
	if (!(env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "TEST")))
		return (-1);
	img.img = mlx_new_image(env.mlx, 250, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.size_line, &img.endian);

	if (read_line(&r, av))
		ft_putnbrendl(r.n_line);
	else
		return (-1);
	if (ac &&av)
	//	line(&img, 200, 150, 100, 150);
	grid(&img, &r);

	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 300);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
