/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:51:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/24 11:34:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	int			fd;
	t_read		r;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(read_file(fd, &r)))
			error_exit("Invalid File");
		if ((close(fd) == -1))
			error_exit("Close Error");
		start_env(&r);
	}
	else
		ft_putendl("To use fdf:\n./fdf <map>\n");
	return (0);
}
