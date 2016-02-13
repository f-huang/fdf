/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:48:51 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/13 17:33:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	relief_plus(t_env *e, t_img *img)
{
	int		i;
	int		j;
	
	j = 0;
	while (j < e->r->n_line)
	{
		i = 0;
		while (i <e-> r->len_line[j])
		{
			if (e->r->data[j][i] != 0)
			{
				e->r->data[j][i] += RELIEF;
				if (e->r->data[j][i] == 0)
					e->r->data[j][i] += RELIEF;
			}
			i++;
		}
		j++;
	}
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	go(e);
}

void	relief_minus(t_env *e, t_img *img)
{
	t_read	*r;
	int		i;
	int		j;
	
	r= e->r;
	j = 0;
	while (j < r->n_line)
	{
		i = 0;
		while (i < r->len_line[j])
		{
			if (e->r->data[j][i] != 0)
			{
				e->r->data[j][i] -= RELIEF;
				if (e->r->data[j][i] == 0)
					e->r->data[j][i] -= RELIEF;
			}
			i++;
		}
		j++;
	}
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, img->img);
	go(e);
}