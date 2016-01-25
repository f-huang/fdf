# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 10:33:23 by fhuang            #+#    #+#              #
#    Updated: 2016/01/25 17:15:59 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

SRC = main.c \

OBJ = $(addprefix $(OBJ_PATH),$(SRC:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all : $(SRC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_PATH) -o $(NAME)
	$(MAKE) -C libft

$(OBJ_PATH)%.o : %.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all
