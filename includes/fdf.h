/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:47:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/15 19:01:30 by fhuang           ###   ########.fr       */
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
# include <math.h>
# include "libft.h"
# include "get_next_line.h"




#include <stdio.h>

# define SIZE_X 1024
# define SIZE_Y 1024
# define WIDTH 1000
# define HEIGHT 1000

# define X 175
# define Y 300

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
# define BRACKET_1 33
# define BRACKET_2 30

# define SPACE 30
# define RELIEF 5

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
	int		x;
	int		y;
}						t_img;

typedef struct			s_env
{
	void	*win;
	void	*mlx;
	t_img	img;
	t_read	*r;
	int		space;
	int		posx;
	int		posy;
}						t_env;

typedef struct			s_coord
{
	double		x;
	double		y;
}						t_coord;

int						print_data(t_read *r);

/*
** MLX
*/

int						read_file(int fd, t_read *r);
int						start_env(t_read *r);
void					dot_at_dot(t_env *e);//, t_img *img);
void					exit_key(t_env *e, t_img *img);
int						keys(int keycode, t_env *e);
void					error_exit(char *str);
void					go(t_env *e);
/*
** LINE
*/

void					put_pixel_img(t_img *img, int x, int y, int color);
void					line(t_env *e, int x1, int y1, int x2, int y2);
void					line_ver(t_env *e, int x, int y);




t_coord					three_toto(int x, int y, int z);


/*
** TRANSLATION
*/

void					go_right(t_env *e, t_img *img);
void					go_left(t_env *e, t_img *img);
void					go_up(t_env *e, t_img *img);
void					go_down(t_env *e, t_img *img);

/*
** ZOOM
*/

void					zoom_in(t_env *e, t_img *img);
void					zoom_out(t_env *e, t_img *img);

/*
** RELIEF
*/

void					relief_plus(t_env *e, t_img *img);
void					relief_minus(t_env *e, t_img *img);


#endif
