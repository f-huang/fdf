/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:02:02 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:32:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sfinal;
	int		i;
	int		j;

	if (!(sfinal = (char*)malloc(sizeof(char) * (ft_strlen(s1))
		+ ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sfinal[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sfinal[i] = s2[j];
		i++;
		j++;
	}
	sfinal[i] = '\0';
	return (sfinal);
}
