# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 14:30:12 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/02 17:41:37 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	$(GCC) $(FLAGS) 

GCC =	gcc

FLAGS =	-Wall -Wextra -Werror

AR =	ar -rcs

NAME =	libft.a

SRCS =	$(shell find . -name '*.c')	

OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

$(SRCS) :
	$(GCC) -o $(OBJS) -c $(SRCS) $(FLAGS) 

$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all
