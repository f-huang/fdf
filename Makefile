# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/02/08 17:57:51 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = fdf.c			\
	  check_file.c	\
	  main.c		\

OBJ = $(addprefix $(OBJ_PATH),$(SRC:%.c=%.o))

HEADER = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT_PATH) -o $(NAME)
	@$(MAKE) -C libft

$(OBJ_PATH)%.o : %.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)

re : fclean all

