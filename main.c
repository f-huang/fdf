/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:59:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/20 18:24:11 by fhuang           ###   ########.fr       */
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

void	draw_sqr(t_img *img)
{
	int		x;
	int		y;
	char	tab[3]={255 ,0, 0};

	y = 0;
	while (y < 250)
	{
		x = 0;
		while (x < img->size_line)
		{
			img->addr[y * img->size_line + x] = tab[0];
			img->addr[y * img->size_line + ++x] = tab[1];
			img->addr[y * img->size_line + ++x] = tab[2];
			x += 2;
		}
		y++;
	}
}

int		find_a(t_img *img, int x1, int y1, int x2, int y2)
{
	int		a;
	int		x;
	int		y;
	int		ret;
	int		i;

	i = 0;
	a = 0;
	if (y2 != y1)
		a = (x2 - x1) / (y2 -y1);
	printf("COEF DIR :%i\n", a);
//	img->addr[0] = 255;
//	img->addr[1004] = 255;
//	img->addr[2008] = 255;
//	img->addr[3012] = 255;
//	img->addr[4016] = 255;
//	img->addr[5020] = 255;
//	img->addr[6024] = 255;
	x = 0;
	while (x < 500)
	{
		y = a * i;
		ret = y * img->size_line + x;
		img->addr[ret] = 255;
		x += 4;
		i++;
	}
	return (0);
}

int		main()
{
	t_env	env;
	t_img	img;

	if (!(env.mlx = mlx_init()))
		return (-1);
	if (!(env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "TEST")))
		return (-1);
	img.img = mlx_new_image(env.mlx, 250, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.size_line, &img.endian);
	find_a(&img, 0, 0, 3, 3);
//	printf("%i\n", img.size_line);
	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 300);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
