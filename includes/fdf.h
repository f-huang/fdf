/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:47:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/02/16 19:26:50 by fhuang           ###   ########.fr       */
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
# include "../libft/libft.h"

#include <stdio.h>

# define SIZE_X 1024
# define SIZE_Y 1024
# define WIDTH 1000
# define HEIGHT 800

# define X 300
# define Y 500

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
# define KEY_SPACE 49
# define BRACKET_1 33
# define BRACKET_2 30
# define COMA 43
# define DOT 47


# define SPACE 20
# define RELIEF 5
# define ZOOM 5
# define ROTATE_1 0.1
# define ROTATE_2 0.1

#define OMEGA (20 * (M_PI / 180))
#define ALPHA (220 * (M_PI / 180))

typedef struct			s_angle
{
	float		omega;
	float		alpha;
	float		cos_omega;
	float		sin_omega;
	float		cos_alpha;
	float		sin_alpha;
}						t_angle;

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
	int		blue;
	int		green;
	int		red;
}						t_img;

typedef struct			s_env
{
	void	*win;
	void	*mlx;
	t_img	img;
	t_read	*r;
	t_angle	ang;
	int		space;
	int		posx;
	int		posy;
}						t_env;

typedef struct			s_coord
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
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

void					put_pixel_img(t_img *img, int x, int y);
void					line(t_env *e, t_coord *s);

/*
** COLOR
*/

void					switch_colors(t_env *env, t_img *img);

/*
** PARALLELES
*/

void					calcul_hor(t_env *e, t_coord *s, int i, int j);
void					calcul_ver(t_env *e, t_coord *s, int i, int j);


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

/*
** ROTATE
*/

void					rotate_w(t_env *e, t_img *img);
void					rotate_s(t_env *e, t_img *img);
void					rotate_a(t_env *e, t_img *img);
void					rotate_d(t_env *e, t_img *img);
#endif
