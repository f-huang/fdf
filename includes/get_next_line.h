/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:57:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/15 10:40:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE  1

int				get_next_line(int const fd, char **line);

typedef struct	s_gnl
{
	int		fd;
	char	*lfo;
}				t_gnl;

#endif
