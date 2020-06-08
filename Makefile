# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 16:33:14 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/08 15:35:17 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
DEPS	=	libft mlx
SRCS	=	main.c
HEADS	=	miniRT.h
CC		=	clang
#CFLAGS	=	-Wall -Werror -Wextra -O3 -g
CFLAGS	=	-O3 -g
IFLAGS	=	-I$(INC) -I./mlx -L./mlx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
OBJS	=	$(SRCS:.c=.o)
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
FLAGS	=	$(CFLAGS) $(INCFLAGS)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(IFLAGS)

%.o		:	%.c
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean	all

$(DEPS)	:
	cd $@ && $(MAKE)
