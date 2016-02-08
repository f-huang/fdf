/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:51:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/08 17:55:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(char *str)
{
	if (!ft_strcmp(str, "file"))
	{
		ft_putendl("Fichier invalide");
		return (0);
	}
	else if (!ft_strcmp(str, "file"))
	{
		ft_putendl("Env invalide");
		return (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_read	r;

	fd = open(av[1], O_RDONLY);
	if (ac)
	printf("FD : %i\n", fd);
	if (!(read_file(fd, &r)))
		return (error("file"));
//	printf("FD : %i\n", fd);
	if (!(init_env(&r)))
		return (error("env"));
	return (0);
}
