/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:54:45 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/30 11:40:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*troncon;
	size_t	j;

	troncon = (char*)malloc(sizeof(char) * (len + 1));
	if (troncon == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		troncon[j] = s[start + j];
		j++;
	}
	troncon[j] = '\0';
	return (troncon);
}
