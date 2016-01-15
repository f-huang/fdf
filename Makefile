# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 10:33:23 by fhuang            #+#    #+#              #
#    Updated: 2016/01/15 11:37:35 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

HEADER = -I includes/

LIBFT_PATH = libft/libft.a

