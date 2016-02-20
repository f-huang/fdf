/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:24:43 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/20 17:24:52 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_ang(t_angle *ang)
{
	ang->cos_omega = cos(ang->omega);
	ang->sin_omega = sin(ang->omega);
	ang->cos_alpha = cos(ang->alpha);
	ang->sin_alpha = sin(ang->alpha);
}

void		calcul_hor(t_env *e, t_coord *s, int i, int j)
{
	get_ang(&e->ang);
	s->x1 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (e->ang.cos_omega * ++i + e->ang.sin_omega * j);
	s->y2 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
}

void		calcul_ver(t_env *e, t_coord *s, int i, int j)
{
	get_ang(&e->ang);
	s->x1 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * ++j);
	s->y2 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
}
