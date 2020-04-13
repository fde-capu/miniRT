# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 05:12:07 by fde-capu          #+#    #+#              #
#    Updated: 2020/04/13 17:36:19 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS = main.c
PNAME = a.out
GCC = gcc
FLAGS = -Wall -Wextra -Werror -O3
LIBS = -Lmlx -lmlx -lm -no-pie -lX11 -lXext
OBJS = $(SRCS:.c=.o)
DEPOBJS = $(DEPPATH)/*.c
DEPPATH = ./libft
DEPLIB = libft.a
DEPLSHORT = ft

all:	$(NAME) 

$(NAME):	$(OBJS) $(DEOPOBJS)
	$(GCC) $(FLAGS) $(OBJS) $(DEPOBJS) $(LIBS) -o $(PNAME)

dep:
	cd libft && $(MAKE)

clean:
	rm -f $(OBJS)

re:		fclean $(NAME)

t:	all
	./$(PNAME)

lame:
	$(GCC) main.c $(LIBS) -o $(PNAME)

.PHONY:	all clean fclean re t lame
