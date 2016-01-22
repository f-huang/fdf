/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:13:54 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/22 15:32:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*tabatoi(char **tab, t_read *r)
{
	int		i;
	int		j;
	int		atoi;
	int		*ret;

	if (!(ret = (int*)ft_memalloc(sizeof(int) * (ft_tablen(tab) + 2))))
		return (0);
	i = 0;
	ret[i] = r->n_line;
	ret[++i] = ft_tablen(tab);
	r->len_line[r->n_line++] = ft_tablen(tab);
	j = 0;
	while (tab[j])
	{
		atoi = ft_atoi(tab[j]);
		ret[++i] = atoi;
		j++;
	}
	return (ret);
}

int			parse_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '-' && line[i] !=  '+')
			return (0);
		i++;
	}
	return (1);
}

int			cut_line(char *line, t_read **r)
{
	char	**tab;
	int		*tabi;

	if (parse_line(line) && (tab = ft_strsplit(line, ' ')))
		{
			if ((tabi = tabatoi(tab, (*r))))
			{
				if (!((*r)->data[(*r)->i] = (int*)ft_memalloc(sizeof(int) * ft_tablen(tab))))
					return (0);
				(*r)->data[(*r)->i] = tabi;
				(*r)->i++;
				return (1);
			}
			else{
				ft_tabfree(tab);
			}
		}
	
	return (0);
}

int			read_line(t_read *r, char **av)
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open(av[1], O_RDONLY);
	if (!(r->data = (int**)ft_memalloc(sizeof(int*) * 1000)))
		return (0);
	if (!(r->len_line = (int*)ft_memalloc(sizeof(int) * 1000)))
		return (0);
	r->i = 0;
	r->n_line = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		printf("GNL : %i\n", gnl);
		if (gnl == -1)
			return (0);
		if (!(cut_line(line, &r)))
			return (0);
		printf("NB DE LINE : %i\n", r->n_line);
	}
	return (1);
}
/*
int		main(int ac, char **av)
{
	t_read r;
	if (read_line(&r ,av))
		ft_putnbrendl(r.n_line);
	else
		ft_putnbrendl(ac - ac);
	return (0);
}*/
