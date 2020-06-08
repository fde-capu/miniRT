# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 16:33:14 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/08 16:56:24 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mrt
DEPFT	=	libft
DEPMLX	=	minilibx-linux
SRCS	=	main.c
HEADS	=	miniRT.h
CC		=	clang
#CFLAGS	=	-Wall -Werror -Wextra -O3 -g
CFLAGS	=	-O3 -g
IFLAGS	=	-I$(INC) -I./$(DEPMLX) -L./$(DEPMLX) -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
OBJS	=	$(SRCS:.c=.o)
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
FLAGS	=	$(CFLAGS) $(INCFLAGS)
DEPS	=	$(DEPFT) $(DEPMLX)

all		:	$(DEPS) $(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(IFLAGS)

%.o		:	%.c
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean	all

$(DEPMLX)	:
	cd $(DEPMLX) && ./configure && make re

$(DEPFT)	:
	cd $(DEPFT) && $(MAKE)
