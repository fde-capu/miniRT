# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 05:12:07 by fde-capu          #+#    #+#              #
#    Updated: 2020/04/13 15:16:09 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRCS = main.c
PNAME = a.out
GCC = gcc
FLAGS = -Wall -Wextra -Werror -O3
LIBS = -Lmlx -lmlx -lm -no-pie -lX11 -lXext
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(GCC) $(FLAGS) main.c $(LIBS) -o $(PNAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean $(NAME)

t:	all
	./$(PNAME)

lame:
	$(GCC) main.c $(LIBS) -o $(PNAME)

.PHONY:	all clean fclean re t lame
