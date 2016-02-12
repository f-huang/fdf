/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:19:35 by fhuang            #+#    #+#             */
/*   Updated: 2015/11/27 11:35:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh_s;
	int		i;

	fresh_s = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (fresh_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fresh_s[i] = f(i, s[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
