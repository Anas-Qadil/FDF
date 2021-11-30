# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 16:33:38 by aqadil            #+#    #+#              #
#    Updated: 2021/11/30 14:00:57 by aqadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

CC = gcc

SRC = fdf.c

OBJS = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(OBJS) $(MLX) -o $(NAME) libft.a -I fdf.h

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all