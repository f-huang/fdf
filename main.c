/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:59:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/22 15:32:00 by fhuang           ###   ########.fr       */
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

void	find_a(t_img *img, int x1, int y1, int x2, int y2)
{
	int		a;
	int		x;
	int		y;
	int		b;

	a = x2 -x1;
	b = y2 - y1;
	if (a == 0)
	{
		x = 0;
		while (x < img->size_line)
		{
			img->addr[b * img->size_line + x] = 255;
			x += 4;
		}
	}
	else if (b == 0)
	{
		x = 0;
		while (x < img->size_line)
		{
			y = 0;
			while (y < img->size_line)
			{
				img->addr[y * img->size_line + x] = 255;
				y++;
			}
			x += 100;
		}
	}
}

void	draw_sqr(t_img *img, t_read *r)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y < r->n_line)
	{
		x = 0;
		while (x < r->len_line[y])
			x++;
		find_a(img, 0, y, x, y);
		y++;
	}
	i = 0;
	while (i < r->n_line)
	{
		x = 0;
		while (x < r->len_line[i])
		{
			find_a(img,x, 0, x, y);
			y += 4;
		}
		i++;
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
		draw_sqr(&img, &r);


	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 300);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
