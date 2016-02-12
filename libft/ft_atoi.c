/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/15 10:59:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		negatif;

	i = 0;
	res = 0;
	negatif = 1;
	while (ft_isspace((int)str[i]))
		i++;
	if (str[i] == '-')
		negatif = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		res *= 10;
		res += negatif * ((int)str[i] - '0');
		i++;
	}
	return (res);
}
