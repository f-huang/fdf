/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:31:07 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 21:31:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ortho_hor(t_env *e, t_coord *s, int i, int j)
{
	t_angle		*ang;

	ang = &e->ang;
	s->x1 = e->posx + e->space * (cos(ang->omega) * i + sin(ang->omega) * j);
	s->y1 = e->posy + e->space * (sin(ang->alpha) * (sin(ang->omega) * i -\
				cos(ang->omega) * j) + cos(ang->alpha) * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (cos(ang->omega) * ++i + sin(ang->omega) * j);
	s->y2 = e->posy + e->space * (sin(ang->alpha) * (sin(ang->omega) * i -\
				cos(ang->omega) * j) + cos(ang->alpha) * e->r->data[j][i]);
	line(e, s);
}

void		ortho_ver(t_env *e, t_coord *s, int i, int j)
{
	t_angle		*ang;

	ang = &e->ang;
	s->x1 = e->posx + e->space * (cos(ang->omega) * i + sin(ang->omega) * j);
	s->y1 = e->posy + e->space * (sin(ang->alpha) * (sin(ang->omega) * i -\
				cos(ang->omega) * j) + cos(ang->alpha) * e->r->data[j][i]);
	s->x2 = e->posx + e->space * (cos(ang->omega) * i + sin(ang->omega) * ++j);
	s->y2 = e->posy + e->space * (sin(ang->alpha) * (sin(ang->omega) * i -\
				cos(ang->omega) * j) + cos(ang->alpha) * e->r->data[j][i]);
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
