/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 21:32:18 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 12:38:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dynam		*ft_dynam_new(size_t type_size)
{
	t_dynam		*res;

	if (!(res = (t_dynam*)malloc(sizeof(t_dynam))))
		return (NULL);
	res->type_size = type_size;
	res->max_elem = SIZE_DYNAM;
	res->nb_elem = 0;
	if (!(res->data = malloc(SIZE_DYNAM * type_size)))
		return (NULL);
	return (res);
}
