/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 11:18:40 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/11 12:59:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	x *= 4;
	img->addr[y * img->size_line + ++x] = color;//COLOR WRONG
	if (color != 255)
	img->addr[y * img->size_line + ++x] = color; //COLOR WRONG
}


