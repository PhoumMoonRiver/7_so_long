# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 15:31:51 by njerasea          #+#    #+#              #
#    Updated: 2023/02/02 16:42:35 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	so_long.c \
		error_check/check_file_input.c \
		error_check/check_map1.c \
		error_check/check_map2.c \
		error_check/check_map3.c \
		error_check/check_path.c \
		error_check/ft_floodfill.c \
		make_map/make_map1.c \
		walking/walk_map1.c \
		make_map/make_map2.c \
		libft/ft_free2d.c \
		libft/ft_putstr.c \
		libft/ft_strcmp.c \
		libft/ft_printint.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/ft_strlen_mo.c \
		debug/ft_debug.c

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) so_long.h.gch
	$(RM) so_long.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

p: fclean all
	./so_long ./maps/map1.ber

.PHONY: all clean fclean re
