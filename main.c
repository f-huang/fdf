/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:59:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/18 19:42:53 by fhuang           ###   ########.fr       */
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

void	draw_img(t_img *img)
{
	int		x;
	int		y;
	char	tab[3]={255 ,0, 0};

	y = 0;
	while (y < 250)
	{
		x = 0;
		while (x < 250)//img->size_line)
		{
			img->addr[y * img->size_line + x] = tab[0];
			img->addr[y * img->size_line + ++x] = tab[1];
			img->addr[y * img->size_line + ++x] = tab[2];
			x += 2;
		}
		y++;
	}
}




int		main()
{
	t_env	env;
	t_img	img;

	if (!(env.mlx = mlx_init()))
		return (-1);
	if (!(env.win = mlx_new_window(env.mlx, 500, 500, "TEST")))
		return (-1);
	img.img = mlx_new_image(env.mlx, 250, 250);
	img.addr = mlx_get_data_addr(img.img, &img.bpb, &img.size_line, &img.endian);
	draw_img(&img);
//	printf("%i\n", img.size_line);
	mlx_put_image_to_window(env.mlx, env.win, img.img, 10, 10);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
