/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/25 17:15:53 by fhuang           ###   ########.fr       */
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
			draw(img, r->data[y][x], r->data[y][x + 1], y);
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
//	get_data(r, &img);
//	draw(&img, 0, 0 ,5);
	
	
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 300);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (1);
}
