/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e->ang.es.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhue->ang.<fhue->ang.student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:28:49 by fhue->ang.           #+#    #+#             */
/*   Updated: 2016/02/16 23:39:59 by fhuang           ###   ########.fr       */
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
	s->x1 = X + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = Y + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = X + e->space * (e->ang.cos_omega * ++i + e->ang.sin_omega * j);
	s->y2 = Y + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
}

void		calcul_ver(t_env *e, t_coord *s, int i, int j)
{
	get_ang(&e->ang);
	s->x1 = X + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = Y + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = X + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * ++j);
	s->y2 = Y + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i - e->ang.cos_omega) + e->ang.cos_alpha * e->r->data[j][i]);
}
