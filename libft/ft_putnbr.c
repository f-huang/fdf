/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:23:31 by fhuang            #+#    #+#             */
/*   Updated: 2015/12/01 21:27:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	uin;

	if (n < 0)
	{
		ft_putchar('-');
		uin = (unsigned int)-n;
	}
	else
		uin = (unsigned int)n;
	if (uin >= 10)
		ft_putnbr(uin / 10);
	ft_putchar(uin % 10 + '0');
}
