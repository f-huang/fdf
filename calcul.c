/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:31:07 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 18:54:18 by fhuang           ###   ########.fr       */
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

void		ortho_hor(t_env *e, t_coord *s, int i, int j)
{
	get_ang(&e->ang);
	s->x1 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i -\
				e->ang.cos_omega) - e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (e->ang.cos_omega * ++i + e->ang.sin_omega * j);
	s->y2 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i -\
				e->ang.cos_omega) - e->ang.cos_alpha * e->r->data[j][i]);
	line(e, s);
}

void		ortho_ver(t_env *e, t_coord *s, int i, int j)
{
	get_ang(&e->ang);
	s->x1 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * j);
	s->y1 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i -\
				e->ang.cos_omega) - e->ang.cos_alpha * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (e->ang.cos_omega * i + e->ang.sin_omega * ++j);
	s->y2 = e->posy + e->space * (e->ang.sin_alpha * (e->ang.sin_omega * i -\
				e->ang.cos_omega) - e->ang.cos_alpha * e->r->data[j][i]);
	line(e, s);
}

void		iso_hor(t_env *e, t_coord *s, int i, int j)
{
	s->x1 = e->posx + e->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	s->y1 = e->posy + e->space * (((1 / sqrtf(6)) * (i + j)) -\
			(sqrtf(2) / sqrtf(3)) * e->r->data[j][i]);
	s->x2 = e->posx + e->space * ((sqrtf(2) / 2) * ++i - ((sqrtf(2) / 2) * j));
	s->y2 = e->posy + e->space * (((1 / sqrtf(6)) * (i + j)) -\
			(sqrtf(2) / sqrtf(3)) * e->r->data[j][i]);
	line(e, s);
}

void		iso_ver(t_env *e, t_coord *s, int i, int j)
{
	s->x1 = e->posx + e->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	s->y1 = e->posy + e->space * (((1 / sqrtf(6)) * (i + j)) -\
			(sqrtf(2) / sqrtf(3)) * e->r->data[j][i]);
	s->x2 = e->posx + e->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * ++j));
	s->y2 = e->posy + e->space * (((1 / sqrtf(6)) * (i + j)) -\
			(sqrtf(2) / sqrtf(3)) * e->r->data[j][i]);
	line(e, s);
}