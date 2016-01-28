/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:53:49 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/28 17:11:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_line(char *line)
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

int		line_to_2dint(t_read **r, char *line)
{
	char	**tab;

	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
	if (!(*r)->data && !((*r)->data = (int**)malloc(sizeof(int*) * ft_tablen(tab))))
		return (0);
	printf("TABLEN :%zu\n", ft_tablen(tab));
	if (!((*r)->data[(*r)->i] = ft_tabatoi(tab)))
		return (0);
	if (!(*r)->len_line && !((*r)->len_line = (int*)malloc(sizeof(int) * ft_strlen(line))))
		return (0);
	(*r)->len_line[(*r)->i] = ft_strlen(line);
	(*r)->n_line++;
	if ((*r)->i > 0 && (*r)->len_line[(*r)->i] != (*r)->len_line[(*r)->i - 1])
		return (0);
	(*r)->i++;
	return (1);
}

int		read_file(int fd, t_read *r)
{
	char	*line;
	int		gnl;

	r->i = 0;
	r->n_line = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1 || !(check_line(line)))
		{
			printf("GNL || FILE CONTENT\n");
			return (0);
		}
		if (!(line_to_2dint(&r, line)))
		{
			printf("HERE\n");
			return (0);
		}
		if (r->data[0] == NULL)
		{
			printf("NOOO\n");
			return (0);
		}
	}
	return (1);
}
