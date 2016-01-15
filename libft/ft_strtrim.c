/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:11:26 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/09 15:57:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*swb;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = ft_strlen(s) - 1;
	while (ft_space((int)s[i]) == 1)
	{
		i++;
		if (s[i] == '\0')
			return (((char*)s) + i);
	}
	while (ft_space((int)s[end]) == 1)
		end--;
	if (!(swb = (char*)malloc(sizeof(char) * (end - i + 2))))
		return (NULL);
	while (i <= end)
		swb[j++] = s[i++];
	swb[j] = '\0';
	return (swb);
}
