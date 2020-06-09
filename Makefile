# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 16:33:14 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/09 10:44:45 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mrt
ARGV	=	mini.rt
SRCS	=	main.c	ext_rt_1.c
HEADS	=	minirt.h
DEPFT	=	libft
DEPMLX	=	minilibx-linux
CC		=	clang
#CFLAGS	=	-Wall -Werror -Wextra -O3 -g
CFLAGS	=	-O3 -g
IFLAGS	=	-I$(INC) -I./$(DEPMLX) -L./$(DEPMLX) -lmlx -L./$(DEPFT) -lft -L$(INCLIB) -lXext -lX11 -lm -lbsd
OBJS	=	$(SRCS:.c=.o)
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
FLAGS	=	$(CFLAGS) $(IFLAGS)
DEPS	=	$(DEPFT) $(DEPMLX)
VALGRIND=	valgrind --leak-check=full

all		:	$(DEPS) $(HEADS) $(NAME)

$(NAME)	:	$(OBJS) $(HEADS)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS)

%.o		:	%.c $(HEADS)
	$(CC) -c $(FLAGS) $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

ffclean	:	fre	fclean

re		:	fclean	all

$(DEPFT)	: ./$(DEPFT)/$(DEPFT).a
./$(DEPFT)/$(DEPFT).a	:
	cd $(DEPFT) && $(MAKE)

$(DEPMLX)	: ./$(DEPMLX)/libmlx.a
./$(DEPMLX)/libmlx.a	:
	cd $(DEPMLX) && ./configure && $(MAKE)

rt		:	ffclean t
fre		:
	cd $(DEPFT) && make fclean
	cd $(DEPMLX) && make clean

t		:	all
	-./$(NAME) $(ARGV)
v		:	all
	$(VALGRIND) ./$(NAME) $(ARGV)
rv		:	ffclean	v
