# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 14:30:12 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/11 14:45:23 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	$(GCC) $(FLAGS) 

GCC		=	clang

FLAGS	=	-Wall -Wextra -Werror -g

AR		=	ar -rcs

SRCS	=	$(shell find . -name '*.c' ! -name "main.c")

HEADS	=	$(shell find . -name '*.h')

CHILD	=	libbezier

OBJS	=	$(SRCS:.c=.o)

all		:	$(HEADS) $(CHILD) $(NAME)

$(SRCS)	:
	$(GCC) -o $(OBJS) -c $(SRCS) $(FLAGS) 

$(NAME)	:	$(OBJS) $(HEADS)
	$(AR) $(NAME) $(OBJS)

$(CHILD) :
	cd $(CHILD) && $(MAKE)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

fcleano	:	fclean
	rm -f *.o
