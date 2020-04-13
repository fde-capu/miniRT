# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/13 05:12:07 by fde-capu          #+#    #+#              #
#    Updated: 2020/04/13 05:19:39 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PNAME = a.out
GCC = gcc -Wall -Wextra -Werror

all:
	$(GCC) main.c -o $(PNAME)

t:	all
	./$(PNAME)
