# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 20:02:48 by lfelipe-          #+#    #+#              #
#    Updated: 2021/10/07 01:09:29 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

NAME	= fractol

SRCS	= main.c ft_mandelbrot.c ft_parse.c ft_draw.c ft_color.c ft_initialize.c \
		  ft_pixel_put.c ft_hook.c ft_julia.c ft_free.c ft_check_julia_args.c \
		  ft_zoom.c ft_burning_ship.c ft_tricorn.c

SDIR	= ./src/

OBJS	= $(addprefix $(ODIR), $(SRCS:.c=.o))

ODIR	= ./obj/

CLIBX	= ./minilibx-linux/libmlx_Linux.a

CLIBFT	= ./libft/libft.a

INCLUDE = -I ./minilibx-linux

LIBX	= -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -L./libft -lft

RM		= rm -rf

$(ODIR)%.o:	$(SDIR)%.c
			@mkdir -p $(ODIR)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(CLIBX) $(CLIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBX) $(INCLUDE) -o $(NAME)

$(CLIBFT):		
			make -C ./libft

$(CLIBX):
			make all -C ./minilibx-linux

clean:
			$(RM) $(OBJS) $(ODIR)
			make clean -C ./minilibx-linux
			make clean -C ./libft

fclean:    	clean
			rm -rf $(NAME) $(ODIR) $(CLIBFT) $(CLIBX)

re:			fclean all

.PHONY:		all clean fclean re
