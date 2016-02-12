/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:07:56 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 16:13:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dst;

	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (n && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	while (n > 0)
	{
		dst[i++] = '\0';
		n--;
	}
	return (dst);
}
