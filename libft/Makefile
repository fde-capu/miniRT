# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 14:30:12 by fde-capu          #+#    #+#              #
#    Updated: 2020/06/11 20:29:07 by fde-capu         ###   ########.fr        #
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

ELINE	=	echo	""; echo ""
LINE	=	echo	"================== from $(NAME) ==============================================="
PUTS	=	echo	
T0		=	$(ELINE); $(LINE); $(PUTS)
T2		=	; $(LINE)

all		:	$(HEADS) $(CHILD) $(NAME)
	@$(T0) ALL DONE! $(T2); $(ELINE)

$(SRCS)	:
	@$(T0) Create object $(OBJS): $(T2)
	$(GCC) -o $(OBJS) -c $(SRCS) $(FLAGS) 

$(NAME)	:	$(OBJS) $(HEADS)
	@$(T0) Compiling library: $(T2)
	$(AR) $(NAME) $(OBJS)

$(CHILD) :
	@$(T0) Make child $(CHILD): $(T2)
	cd $(CHILD) && $(MAKE)

clean	:
	@$(T0) Clean: $(T2)
	rm -f $(OBJS)

fclean	:	clean
	@$(T0) Full: $(T2)
	rm -f $(NAME)

re		:	fclean all
