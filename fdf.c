/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/15 19:01:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_at_dot(t_env *e)//, t_img *img)
{
	int		x;
	int		y;
	int		i;
	int		j;
	t_coord	s;

	y = e->img.y;
	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		x = e->img.x;
		while (i < e->r->len_line[j])
		{
			if (i + 1 < e->r->len_line[j])
			{
		//		line(e, x, y - e->r->data[j][i], x + SPACE, y - e->r->data[j][i + 1]);
				s = three_toto(i, j, e->r->data[j][i + 1]);
//				line(e, x, y -e->r->data[j][i], s.x, s.y - e->r->data[j][i]);
				line(e, x, y, s.x, s.y);
			}
		//	if (j + 1 < e->r->n_line)
		//		line_ver(e, x, y);
			x += SPACE;
			i++;
		}
		y += SPACE;
		j++;
	}
}

void	contour(t_env *e)
{
	for (int i = 0; i < (&e->img)->size_line; i+=4)
		(&e->img)->addr[i] = 255;
	for (int i = 0; i < WIDTH; i++)
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
	e->img.x = X;
	e->img.y = Y;
	dot_at_dot(e);// (&e)->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, e->posx, e->posy);
}


int		start_env(t_read *r)
{
	t_env		e;

	if (r->i++ == 0)
	{
		e.posx = 0;
		e.posy = 0;
		e.r = r;
		if (!(e.mlx = mlx_init()))
			return (0);
		if (!(e.win = mlx_new_window(e.mlx, SIZE_X, SIZE_Y, "MLX")))
			return (0);

	}//////////////////////////////////////////////////////////////////////////



	go(&e);

	mlx_key_hook(e.win, keys, &e);
	mlx_loop(e.mlx);

	//////////////////////////////////////////////////////////////////////////
	return (1);
}
