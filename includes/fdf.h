/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:47:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/18 19:42:51 by fhuang           ###   ########.fr       */
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

#endif
