# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 14:22:40 by fde-capu          #+#    #+#              #
#    Updated: 2020/09/02 19:55:26 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS	=	0
NAME	=	libftmlx.a
#DEPMLX	=	minilibx-linux
#DEPMLXLIB=	libmlx.a
#INC		=	/usr/include
#INCLIB	=	$(INC)/../lib
#DEPFT	=	../libft
#IFLAGS	=	-I../$(DEPMLX) -L../$(DEPMLX) -lmlx \
			-I$(INC) -L$(INCLIB) -lXext -lX11 -lm -lbsd \
			-I$(DEPFT) -L$(DEPFT) -lft
#DEPS	=	$(DEPMLX) $(DEPFT)
CC		=	clang
AR		=	ar -rcs
CFLAGS	=	-Wall -Wextra -Werror -g -O3 -DBONUS=$(BONUS)
#CFLAGS	=	-O3 -g
#FLAGS	=	$(CFLAGS) $(IFLAGS)
SRCS	=	ftmlx.c	pixels.c render_1.c render_2.c pjt.c cam_faces_1.c
HEADS	=	ftmlx.h
OBJS	=	$(SRCS:.c=.o)
ELINE	=	echo	""; echo ""
LINE	=	echo	"================== from $(NAME) ==============================================="
PUTS	=	echo	
T0		=	$(ELINE); $(LINE); $(PUTS)
T2		=	; $(LINE)

#all		:	$(DEPS) $(HEADS) $(NAME)
all		:	$(HEADS) $(NAME)
	@$(T0) ALL DONE! $(T2); $(ELINE)

$(NAME)	:	$(HEADS) $(OBJS)
	@$(T0) Compiling library $(T2)
	$(AR) $(NAME) $(OBJS)

%.o		:	%.c
	@$(T0) Create object $@ : $(T2)
	$(CC) -c $(CFLAGS) $< -o $@

clean	:
	@$(T0) Clean $(T2)
	rm -f $(OBJS)

fclean	:	clean	clean_d
	@$(T0) Full $(T2)
	rm -f $(NAME)

clean_d	:
	@$(T0) "Cleaning dependency:" $(DEPMLX) $(T2)
	cd ../$(DEPMLX) && make clean

re		:	fclean all

#$(DEPMLX)	:	../$(DEPMLX)/$(DEPMLXLIB)
#../$(DEPMLX)/$(DEPMLXLIB)	:
#	@$(T0) "MAKE (dep) :: " $(DEPMLX) $(T2)
#	cd ../$(DEPMLX) && $(MAKE)
#
#$(DEPFT)	:	$(DEPFT)/$(DEPFT).a
#$(DEPFT)/$(DEPFT).a	:
#	@$(T0) "MAKE (dep) :: " $(DEPFT) $(T2)
#	cd $(DEPFT) && $(MAKE)
