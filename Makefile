# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/02/22 16:03:46 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c			\
	  check_file.c		\
	  keyhook.c			\
	  fdf.c				\
	  draw.c			\
	  rotate.c			\
	  translation.c		\
	  zoom.c			\
	  angles.c			\
	  brackets.c		\
	  color.c

OBJ = $(addprefix $(OBJ_PATH),$(SRC:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT_PATH) -o $(NAME)
#	@$(MAKE) re -C libft

$(OBJ_PATH)%.o : %.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(HEADER_PATH) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
#	@$(MAKE) clean -C libft

fclean: clean
	@rm -f $(NAME)

re : fclean all

