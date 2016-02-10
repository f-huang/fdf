/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:51:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/10 18:19:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_exit(char *str)
{
	ft_putendl(str);
	exit(-1);
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
//	if (!(init_env(&r)))
//		return (error("env"));
	return (0);
}
