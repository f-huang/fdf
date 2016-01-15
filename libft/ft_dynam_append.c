/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynam_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 21:44:48 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/11 16:13:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dynam_append(t_dynam *dynam, void *new_data, size_t nb_data)
{
	size_t	mult;
	void	*tmp;

	if (dynam->data == NULL)
	{
		if (!(dynam->data = malloc(dynam->type_size * nb_data)))
			return (1);
		dynam->max_elem = nb_data;
		dynam->nb_elem = 0;
	}
	mult = 1;
	while (nb_data + dynam->nb_elem > mult * dynam->max_elem)
		mult *= 2;
	if (mult > 1)
	{
		dynam->max_elem *= mult;
		if (!(tmp = malloc(dynam->max_elem * dynam->type_size)))
			return (1);
		ft_memcpy(tmp, dynam->data, (dynam->nb_elem * dynam->type_size));
		free(dynam->data);
		dynam->data = tmp;
	}
	ft_memcpy(dynam->data + dynam->nb_elem * dynam->type_size,
			new_data, nb_data * dynam->type_size);
	dynam->nb_elem += nb_data;
	return (0);
}
