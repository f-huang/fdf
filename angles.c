/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:28:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/15 19:01:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define FACT 10
#define OMEGA (10 * (M_PI / 180))
#define ALPHA (10 * (M_PI / 180))

t_coord		three_toto(int x, int y, int z)
{
	double	xx;
	double		yy;
	t_coord	s;

	xx = X + FACT * (cos(OMEGA) * x + sin(OMEGA) * y);
	yy = Y + FACT * (sin(ALPHA) * (sin(OMEGA) * x - cos(OMEGA) * y) + cos(ALPHA) * z);
	
	s.x = xx;
	s.y = yy;

	printf("XX : %f\n", xx);
	printf("YY : %f\n", yy);
	return (s);
}
