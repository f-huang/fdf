/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:47:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/09 12:06:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"




#include <stdio.h>

# define SIZE_X 1024
# define SIZE_Y 1024
# define WIDTH 500
# define HEIGHT 500
# define SPACE 30

typedef struct			s_read
{
	int		i;
	int		n_line;
	int		*len_line;
	int		**data;
}						t_read;

typedef struct			s_img
{
	void	*img;
	char	*addr;
	int		bpb;
	int		size_line;
	int		endian;
}						t_img;

typedef struct			s_env
{
	void	*win;
	void	*mlx;
}						t_env;

typedef struct			s_coord
{
	int		x;
	int		y;
	int		z;
}						t_coord;

int						read_file(int fd, t_read *r);
int						init_env(t_read *r);

#endif
