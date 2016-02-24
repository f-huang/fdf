/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/24 11:53:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ortho(t_env *e)
{
	int			i;
	int			j;
	t_coord		s;

	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		while (i < e->r->len_line[j])
		{
			if (i + 1 < e->r->len_line[j])
				ortho_hor(e, &s, i, j);
			if (j + 1 < e->r->n_line)
				ortho_ver(e, &s, i, j);
			i++;
		}
		j++;
	}
}

void	iso(t_env *e)
{
	int			i;
	int			j;
	t_coord		s;

	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		while (i < e->r->len_line[j])
		{
			if (i + 1 < e->r->len_line[j])
				iso_hor(e, &s, i, j);
			if (j + 1 < e->r->n_line)
				iso_ver(e, &s, i, j);
			i++;
		}
		j++;
	}
}

void	go(t_env *e)
{
	if (!(e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		error_exit("New image error");
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bpp,\
			&e->img.size_line, &e->img.endian);
	e->projection == 1 ? ortho(e) : (iso(e));
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}

int		start_env(t_read *r)
{
	t_env		e;

	e.posx = X;
	e.posy = Y;
	e.r = r;
	e.projection = 1;
	if (!(e.mlx = mlx_init()))
		error_exit("Environment error");
	if (!(e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "MLX")))
		error_exit("Window error");
	e.ang.omega = OMEGA;
	e.ang.alpha = ALPHA;
	e.space = SPACE;
	go(&e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, keys, &e);
	mlx_loop(e.mlx);
	return (1);
}
