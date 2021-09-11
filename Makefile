# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 20:02:48 by lfelipe-          #+#    #+#              #
#    Updated: 2021/09/10 03:21:22 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

NAME	= fractol

SRCS	= src/main.c src/mandelbrot.c

SDIR	= src

OBJS	= $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)

ODIR	= obj

INCLUDE = -I ./minilibx-linux

LIBX	= -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz

RM		= rm -rf

$(ODIR)/%.o: 	$(SDIR)/%.c
			@mkdir -p obj
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.minilibx:
			make all -C ./minilibx-linux

all:		$(NAME)

$(NAME):	.minilibx $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBX) -o $(NAME)

clean:
			$(RM) $(OBJS) $(ODIR)
			make clean -C ./minilibx-linux

fclean:    	clean
			rm -rf $(NAME) $(ODIR)

re:			fclean all

.PHONY:		all clean fclean
