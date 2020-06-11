# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 16:33:14 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/11 16:30:36 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mrt
ARGV	=	mini.rt
SRCS	=	main.c	ext_rt_1.c	scene_init.c	verbose.c
HEADS	=	minirt.h
D_FTMLX	=	ftmlx
D_LIBFT	=	libft
D_MLXOC	=	minilibx-linux
D_MLX_L	=	libmlx
CC		=	clang
#CFLAGS	=	-Wall -Werror -Wextra -O3 -g
CFLAGS	=	-O3 -g
IFLAGS	=	-I./$(D_FTMLX) -L./$(D_FTMLX) -lftmlx \
			-I./$(D_LIBFT) -L./$(D_LIBFT) -lft \
			-I./$(D_MLXOC) -L./$(D_MLXOC) -lmlx \
			-I$(INC) -L$(INCLIB) \
			-lXext -lX11 -lm -lbsd
OBJS	=	$(SRCS:.c=.o)
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
FLAGS	=	$(CFLAGS) $(IFLAGS)
DEPS	=	$(D_FTMLX) $(D_LIBFT) $(D_MLXOC)
VALGRIND=	valgrind --leak-check=full

all		:	$(DEPS) $(HEADS) $(NAME)

$(D_FTMLX)	: ./$(D_FTMLX)/$(D_FTMLX).a
./$(D_FTMLX)/$(D_FTMLX).a	:
	cd $(D_FTMLX) && $(MAKE)

$(D_LIBFT)	: ./$(D_LIBFT)/$(D_LIBFT).a
./$(D_LIBFT)/$(D_LIBFT).a	:
	cd $(D_LIBFT) && $(MAKE)

$(D_MLXOC)	: ./$(D_MLXOC)/$(D_MLX_L).a
./$(D_MLXOC)/$(D_MLXL).a	:
	cd $(D_MLXOC) && $(MAKE)

$(NAME)	:	$(OBJS) $(HEADS)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS)

%.o		:	%.c $(HEADS)
	$(CC) -c $(FLAGS) $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

ffclean	:	fre	fclean

fffcleano	:
	find . -name "*.o" -exec rm -f {} \;

fffcleana	:
	find . -name "*.a" -exec rm -f {} \;

f			:	fffcleano	fffcleana

re		:	fclean	all

rt		:	ffclean t
fre		:
	cd $(D_FTMLX) && make fclean
	cd $(D_LIBFT) && make fclean
	cd $(D_MLXOC) && make clean

t		:	all
	-./$(NAME) $(ARGV)
v		:	all
	$(VALGRIND) ./$(NAME) $(ARGV)
rv		:	ffclean	v
