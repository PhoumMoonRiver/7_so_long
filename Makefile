# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 15:31:51 by njerasea          #+#    #+#              #
#    Updated: 2022/12/18 09:01:51 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	solong.c \
		error_check/check_file_input.c \
		error_check/check_map1.c \
		error_check/check_map2.c \
		error_check/check_map3.c \
		error_check/check_path.c \
		error_check/ft_floodfill.c \
		libft/ft_free2d.c \
		libft/ft_putstr.c \
		libft/ft_strcmp.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/ft_strlen_mo.c \
		debug/ft_debug.c
	
CC = gcc -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(NAME)
	$(RM) so_long.h.gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

p: clean all
	./so_long ./maps/map1.ber

.PHONY: all clean fclean re 