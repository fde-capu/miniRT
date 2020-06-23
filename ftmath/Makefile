# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:33:18 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/23 14:49:00 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftmath.a
SRCS	=	ftmath_verb.c	ftmath_verb2.c	scene_destroy.c	\
			scene_init.c	scene_init2.c	scene_add.c
HEAD	=	ftmath.h
OBJS	=	$(SRCS:.c=.o)
CC		=	clang -g -Wall -Wextra -Werror

all		:	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

.o		:	.c
	clang -g -Wall -Wextra -Werror -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean	all
