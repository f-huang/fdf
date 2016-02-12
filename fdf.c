/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:58:25 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/12 19:50:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dot_at_dot(t_env *e)//, t_img *img)
{
	int		x;
	int		y;
	int		i;
	int		j;

	y = 30;
	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		x = 40;
		while (i < e->r->len_line[j])
		{
			if (i + 1 < e->r->len_line[j])
			{
			//	printf("HE\n");
				put_pixel_img(&e->img, x, y, e->img.color);
			//	printf("HE\n");
				line(&e->img, x, y - e->r->data[j][i], x + SPACE, y - e->r->data[j][i + 1]);
			//	printf("HE\n");
			}
			if (j + 1 < e->r->n_line)
					line_ver(e, x, y);
			x += SPACE;
			i++;
		}
		y += SPACE;
		j++;
	}
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
	
		if (!(e.img.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
			return (0);
			e.img.addr = mlx_get_data_addr(e.img.img, &e.img.bpb, &e.img.size_line, &e.img.endian);
	}//////////////////////////////////////////////////////////////////////////
	
	
	printf("he : %i\n", e);
	dot_at_dot(&e);// (&e)->img);
	
	
	
	
	//////////////////////////////////////////////////////////////////////////
	mlx_put_image_to_window(e.mlx, e.win, e.img.img, e.posx, e.posy);
	mlx_key_hook(e.win, keys, &e);
	mlx_loop(e.mlx);
	return (1);
}
