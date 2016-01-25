/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:54:42 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/25 15:14:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabatoi(char **tab)
{
	int		i;
	int		atoi;
	int		*ret;

	i = 0;
	if (!(ret = (int*)ft_memalloc(sizeof(int) * ft_tablen(tab))))
		return (NULL);
	while (tab[i])
	{
		atoi = ft_atoi(tab[i]);
		ret[i] = atoi;
		i++;
	}
	return (ret);
}
