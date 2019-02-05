# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/09/14 16:26:30 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

C_FIL = main.c initialize.c key_hooks.c draw_image.c \
		loop_hook.c translate.c map.c rotation.c

O_FIL = $(C_FIL:.c = .o)
O_LOC = obj

GCC_FLAGS = gcc -Wall -Wextra -Werror -L miniLibx -lmlx -framework OpenGL \
			-framework AppKit

LIB = libft/libft.a

MLX = miniLibx/libmlx.a

all: $(NAME)

$(LIB):
	cd libft && make

$(MLX):
	cd miniLibx && make

$(NAME): $(O_FIL) $(LIB) $(MLX)
	$(GCC_FLAGS) $(LIB) $^ -o $(NAME)

%.o: %.c ./wolf3d.h
	gcc -c $< -o $@

clean:
		cd libft && make clean

fclean: clean
		cd libft && make fclean
			/bin/rm -f $(NAME)

test: $(NAME)
	./wolf3d

re: fclean all
