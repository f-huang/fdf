/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynam_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:14:45 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 16:16:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dynam_trim(t_dynam *dynam)
{
	void	*tmp;

	if (dynam->max_elem > dynam->nb_elem)
	{
		if (!(tmp = malloc(dynam->type_size * dynam->nb_elem)))
			return (1);
		ft_memcpy(tmp, dynam->data, dynam->nb_elem * dynam->type_size);
		free(dynam->data);
		dynam->data = tmp;
		dynam->max_elem = dynam->nb_elem;
	}
	return (0);
}
