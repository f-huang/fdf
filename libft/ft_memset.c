/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:05:10 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:15:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c_char;
	unsigned char	*p;

	c_char = (unsigned char)c;
	p = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		p[i] = c_char;
		i++;
	}
	return (p);
}
