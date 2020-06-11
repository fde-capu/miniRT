# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 14:22:40 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/11 14:34:52 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftmlx.a

DEPMLX	=	minilibx-linux
DEPMLXLIB=	libmlx.a
INC		=	/usr/include
INCLIB	=	$(INC)/../lib

DEPFT	=	../libft

IFLAGS	=	-I../$(DEPMLX) -L../$(DEPMLX) -lmlx \
			-I$(INC) -L$(INCLIB) -lXext -lX11 -lm -lbsd \
			-L$(DEPFT) -lft

DEPS	=	$(DEPMLX) $(DEPINCLIB)

CC		=	clang
AR		=	ar -rcs

#CFLAGS	=	-Wall -Wextra -Werror -g -O3
CFLAGS	=	-O3 -g

FLAGS	=	$(CFLAGS) $(IFLAGS)

SRCS	=	ftmlx.c	pixels.c

HEADS	=	ftmlx.h

OBJS	=	$(SRCS:.c=.o)

all		:	$(DEPS) $(HEADS) $(NAME)

$(NAME)	:	$(OBJS) $(HEADS)
	$(AR) $(NAME) $(OBJS)

%.o		:	%.c
	$(CC) -c $(FLAGS) $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	cd ../$(DEPMLX) && make clean

re		:	fclean all

fcleano	:	fclean
	rm -f *.o

$(DEPMLX)	:	../$(DEPMLX)/$(DEPMLXLIB)
../$(DEPMLX)/$(DEPMLXLIB)	:
	cd ../$(DEPMLX) && ./configure && $(MAKE)

$(DEPFT)	:	$(DEPFT)/$(DEPFT).a
$(DEPFT)/$(DEPFT).a	:
	cd $(DEPFT) && $(MAKE)
