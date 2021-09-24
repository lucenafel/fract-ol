# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfelipe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 13:22:37 by lfelipe-          #+#    #+#              #
#    Updated: 2021/09/16 16:13:20 by lfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PART1	= ft_atoi.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_memset.c ft_strlcat.c ft_strlen.c \
		  ft_strncmp.c ft_tolower.c ft_toupper.c \
		  ft_memcpy.c ft_memccpy.c ft_bzero.c \
		  ft_strchr.c ft_strrchr.c ft_strlcpy.c \
		  ft_memcmp.c ft_memchr.c ft_memmove.c \
		  ft_strnstr.c ft_calloc.c ft_strdup.c

PART2	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		  ft_putendl_fd.c ft_substr.c ft_strjoin.c \
		  ft_strtrim.c ft_itoa.c ft_split.c \
		  ft_strmapi.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		  ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_OBJ	= $(BONUS:.c=.o)

SRCS	= $(PART1) $(PART2)

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

LIB		= ar -rcs

INCLUDE = libft.h

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror


.c.o:
			$(CC) $(CFLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB) $(NAME) $(OBJS)

all:		$(NAME) bonus

bonus:		$(B_OBJ) $(INCLUDE)
			$(LIB) $(NAME) $(B_OBJ)

clean:
			$(RM) $(OBJS) $(B_OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
