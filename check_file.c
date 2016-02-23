/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:53:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/23 19:02:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_n(int nb)
{
	int		n;

	n = 1;
	while (nb / 10)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

static int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]) && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}


static int		line_to_2dint(t_read *r, char *line)
{
	char		**tab;
	size_t		i;

	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
//	printf("\n--------LINE--------: %s\n", line);
	///////////////////////////
//	int		j = 0;
//	while (tab[j])
//		printf("%s\t", tab[j++]);
	//////////////////////////
	if (!(r->data = (int**)ft_realloc(r->data, sizeof(int*) * (++r->n_line + 1))))
		return (0);
	if (!(r->data[r->i] = (int*)ft_memalloc(sizeof(int) * (ft_tablen(tab) + 1))))
		return (0);
	i = 0;
	while (tab[i])
	{
		r->data[r->i][i] = ft_atoi(tab[i]);
		i++;
	}
	if (!r->len_line && r->i == 0)
		if (!(r->len_line = (int*)ft_memalloc(sizeof(int) * (count_n(ft_tablen(tab) + 1)))))
			return (0);
//	printf("TABLEN: %zu\n", ft_tablen(tab));
	r->len_line[r->i] = ft_tablen(tab);
	r->i++;
	return (1);
}

int		print_data(t_read *r)
{
	int		i;
	int		j;

	j = 0;
	while (j < r->n_line)
	{
		i = 0;
		while (i < r->len_line[j])
		{
			ft_putnbr(r->data[j][i]);
			ft_putstr("  ");
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}

int		read_file(int fd, t_read *r)
{
	char	*line;
	int		gnl;

	r->i = 0;
	r->n_line = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
//		printf("\n////|%s|\\\\\n", line);
		if (gnl == -1 || !(check_line(line)))
		{
			printf("GNL || FILE CONTENT\n");
			return (0);
		}
		if (!(line_to_2dint(r, line)))
		{
			printf("HERE\n");
			return (0);
		}
		bzero(line, ft_strlen(line));
	}
//	print_data(r);
	r->i = 0;
	return (1);
}
