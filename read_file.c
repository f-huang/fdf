/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:13:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/15 12:36:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_line(char *line)
{
	int		i;
	int		ret;
	char	*str;
	int		len;

	while (line[i])
	{
		ret = ft_atoi(line);
		str = ft_itoa(ret);
		len = ft_strlen(line);
	}
}

int		read_fd(int fd)
{
	char	*line;
	int		gnl;

	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (parse_line(line))
			return (-1);
	}
	if (gnl == -1)
		return (-1);
	return (0);
}
