/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:28:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/16 19:26:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define OMEGA (10 * (M_PI / 180))
#define ALPHA (10 * (M_PI / 180))

#define RX 1
#define IMX 1
#define RY 1
#define IMY (-1)
#define RZ 0
#define IMZ 1

void		three_toto(t_env *e, t_coord *s, int i, int j)
{
	s->x = e->img.x * RX + e->img.y * RY + e->r->data[j][i] * RZ;
	s->y = e->img.x * IMX + e->img.y * IMY + e->r->data[j][i] * IMZ;

}
