# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/07 16:33:14 by fde-capu          #+#    #+#              #
#    Updated: 2020/08/20 18:26:20 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
ARGV	=	mini.rt
T_SAVE	=	--save
SRCS	=	minirt.c		events.c	ext_rt_1.c		ext_rt_2.c	\
			bmp.c	
HEADS	=	minirt.h
D_FTMLX	=	ftmlx
D_LIBFT	=	libft
D_FTMAT	=	ftmath
D_MLXOC	=	minilibx-linux
D_MLX_L	=	libmlx
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -O3 -g
IFLAGS	=	-I./$(D_FTMLX) -L./$(D_FTMLX) -lftmlx \
			-I./$(D_FTMAT) -L./$(D_FTMAT) -lftmath \
			-I./$(D_LIBFT) -L./$(D_LIBFT) -lft \
			-I./$(D_MLXOC) -L./$(D_MLXOC) -lmlx \
			-I$(INC) -L$(INCLIB) \
			-lXext -lX11 -lm -lbsd -lz
OBJS	=	$(SRCS:.c=.o)
INC		=	/usr/include
INCLIB	=	$(INC)/../lib
FLAGS	=	$(CFLAGS) $(IFLAGS)
DEPS	=	$(D_FTMLX) $(D_LIBFT) $(D_FTMAT) $(D_MLXOC)
VALGRIND=	valgrind --leak-check=full
ALLLEAKS=	--show-leak-kinds=all
NORM	=	~/.norminette/norminette *.h *.c
ELINE	=	echo	""; echo ""
LINE	=	echo	"================== from $(NAME) =========================="
PUTS	=	echo	
T0		=	$(ELINE); $(LINE); $(PUTS)
T2		=	; $(LINE)

all		:	$(DEPS) $(HEADS) $(NAME)
	@$(T0) Allrighty! $(T2); $(ELINE)

$(D_FTMLX)	: ./$(D_FTMLX)/$(D_FTMLX).a
./$(D_FTMLX)/$(D_FTMLX).a	:
	@$(T0) Child $(D_FTMLX) $(T2)
	cd $(D_FTMLX) && $(MAKE)

$(D_LIBFT)	: ./$(D_LIBFT)/$(D_LIBFT).a
./$(D_LIBFT)/$(D_LIBFT).a	:
	@$(T0) Child $(D_LIBFT) $(T2)
	cd $(D_LIBFT) && $(MAKE)

$(D_FTMAT)	: ./$(D_FTMAT)/lib$(D_FTMAT).a
./$(D_FTMAT)/lib$(D_FTMAT).a	:
	@$(T0) Child $(D_FTMAT) $(T2)
	cd $(D_FTMAT) && $(MAKE)

$(D_MLXOC)	: ./$(D_MLXOC)/$(D_MLX_L).a
./$(D_MLXOC)/$(D_MLX_L).a	:
	@$(T0) Child $(D_MLXOC) $(T2)
	cd $(D_MLXOC) && ./configure && $(MAKE)

$(NAME)	:	$(OBJS) $(HEADS)
	@$(T0) Finally: $(NAME) $(T2)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS)

%.o		:	%.c $(HEADS)
	@$(T0) Create object: $@ $(T2)
	$(CC) -c $(CFLAGS) $< -o $@

clean	:
	@$(T0) "Clean natives:" $(T2)
	rm -f $(OBJS)

fclean	:	clean
	@$(T0) "And full." $(T2)
	rm -f $(NAME)

ffclean	:	fre	fclean
	@$(T0) "All clear!" $(T2)
	@$(ELINE); $(ELINE); $(ELINE)
	@$(ELINE); $(ELINE); $(ELINE)
	@$(ELINE); $(ELINE); $(ELINE)
	@$(ELINE); $(ELINE); $(ELINE)

re		:	fclean	all

rt		:	ffclean t
fre		:
	@$(T0) "Clean dependency:" $(D_FTMLX) $(T2)
	cd $(D_FTMLX) && make fclean
	@$(T0) "Clean dependency:" $(D_LIBFT) $(T2)
	cd $(D_LIBFT) && make fclean
	@$(T0) "Clean dependency:" $(D_FTMAT) $(T2)
	cd $(D_FTMAT) && make fclean

t		:	all
	-./$(NAME) $(ARGV)
v		:	all
	-$(VALGRIND) ./$(NAME) $(ARGV)
vf		:	all
	-$(VALGRIND) $(ALLLEAKS) ./$(NAME) $(ARGV)
rv		:	ffclean	v
ts		:	ffclean	all
	-$(VALGRIND) ./$(NAME) $(ARGV) $(T_SAVE)
s		:	all
	-$(VALGRIND) ./$(NAME) $(ARGV) $(T_SAVE)
norm	:
	$(NORM)
	cd libft && $(NORM) *.h *.c
	cd ftmath && $(NORM) *.h *.c
	cd ftmlx && $(NORM) *.h *.c
