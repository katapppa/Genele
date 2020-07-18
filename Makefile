# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/17 13:42:52 by cgamora           #+#    #+#              #
#    Updated: 2020/07/17 14:30:48 by cgamora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -g -Werror -Wextra -Wall
NAME = fdf
SRC = src/*.c
INCLUDES = libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
