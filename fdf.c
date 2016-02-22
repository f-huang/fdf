/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/22 23:28:57 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_at_dot(t_env *e)//, t_img *img)
{
	int		i;
	int		j;
	t_coord	s;

	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		while (i < e->r->len_line[j])
		{
			if (i + 1 < e->r->len_line[j])
			{
				ortho_hor(e, &s, i, j);
				line(e, &s);
			}
			if (j + 1 < e->r->n_line)
			{
				ortho_ver(e, &s, i, j);
				line(e, &s);
			}
			i++;
		}
		j++;
	}
}

void	contour(t_env *e)
{
	for (int i = 0; i < (&e->img)->size_line; i+=4)
		(&e->img)->addr[i] = 255;
	for (int i = 0; i < HEIGHT - 1; i++)
		(&e->img)->addr[(&e->img)->size_line * i] = 255;
	for (int i = 0; i < HEIGHT - 1; i++)
		(&e->img)->addr[(&e->img)->size_line * i + (&e->img)->size_line - 4] = 255;
	for (int j = 0; j < (&e->img)->size_line; j+=4)
		(&e->img)->addr[((HEIGHT - 1) * (&e->img)->size_line) + j] = 255;
}

void	go(t_env *e)
{
	if (!(e->img.img = mlx_new_image(e->mlx, WIDTH + e->r->i, HEIGHT + e->r->i++)))
		error_exit("IMAGE");


	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bpb, &e->img.size_line, &e->img.endian);

	print_data(e->r);
	contour(e);
	dot_at_dot(e);// (&e)->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}

int		start_env(t_read *r)
{
	t_env		e;

		e.posx = X;
		e.posy = Y;
		e.r = r;
		if (!(e.mlx = mlx_init()))
			error_exit("Environment error");
		if (!(e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "MLX")))
			error_exit("Window error");

	e.ang.omega = OMEGA;
	e.ang.alpha = ALPHA;
	e.space = SPACE;
	go(&e);

//	mlx_key_hook(e.win, keys, &e);
	mlx_hook(e.win, 2, 1, keys, &e);
	mlx_loop(e.mlx);

	//////////////////////////////////////////////////////////////////////////
	return (1);
}
