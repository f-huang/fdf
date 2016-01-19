/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:13:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/19 19:31:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			parse_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int			cut_line(char *line, t_read *r)
{
	char	**tab;
	int		*tabi;

	if (parse_line(line))
		if ((tab = ft_strsplit(line, ' ')))
		{
			if ((tabi = ft_tabatoi(tab)))
			{
				if (!(r->data[r->i] = (int*)ft_memalloc(sizeof(int) * ft_tablen(tab))))
					return (0);
				r->data[r->i] = tabi;
				r->i++;
				return (1);
			}
			else
				ft_tabfree(tab);
		}
	return (0);
}

int			read_line(char **av)
{
	char	*line;
	int		fd;
	int		gnl;
	t_read	r;

	fd = open(av[1], O_RDONLY);
	if (!(r.data = (int**)ft_memalloc(sizeof(int*) * 1000)))
		return (0);
	r.i = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			return (0);
		if (!(cut_line(line, &r)))
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (read_line(av))
		ft_putnbrendl(ac);
	else
		ft_putnbrendl(ac - ac);
	return (0);
}
