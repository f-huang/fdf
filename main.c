/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:51:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/22 17:54:52 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		fd;
	t_read	r;

	fd = open(av[1], O_RDONLY);
	if (ac)
	printf("FD : %i\n", fd);
	if (!(read_file(fd, &r)))
		error_exit("INVALID FILE");
//	printf("FD : %i\n", fd);
	start_env(&r);
	return (0);
}
