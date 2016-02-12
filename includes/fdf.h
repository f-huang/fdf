/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:47:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/12 13:52:53 by fhuang           ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 1000
# define SPACE 30

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define PLUS 69
# define MINUS 78
# define ESC 53
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define KEY_A 0






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
	int		color;
}						t_img;

typedef struct			s_env
{
	void	*win;
	void	*mlx;
	int		posx;
	int		posy;
}						t_env;

typedef struct			s_coord
{
	int		x;
	int		y;
}						t_coord;

int						read_file(int fd, t_read *r);
int						start_env(t_read *r);
void					put_pixel_img(t_img *img, int x, int y, int color);
#endif
