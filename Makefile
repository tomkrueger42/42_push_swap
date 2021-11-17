# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:28:19 by tkruger           #+#    #+#              #
#    Updated: 2021/11/17 21:58:33 by tkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		general
# **************************************************************************** #

INPT = "10 2 5 3 7 5 6 7 8"
NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -o

# **************************************************************************** #
#		SRC
# **************************************************************************** #

SRC = ./src/push_swap.c ./src/list_handling.c ./src/operations.c ./src/snake.c\
		./src/sort.c

# **************************************************************************** #
#		Libs
# **************************************************************************** #

LIBDIR = libs/libft
LIB = -L./$(LIBDIR) -lft
INC = -I./$(LIBDIR)
# for LIB: either -l:libft.a or -lft same same
# will have to copy libft into the intra repo for evaluation!!!

# **************************************************************************** #
#		rules
# **************************************************************************** #

$(NAME): libmake
	$(CC) $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)

all:	$(NAME)

libmake:
	@make -C $(LIBDIR) all
	@make -C $(LIBDIR) clean

clean:
	@rm -f *.o *~
	@make -C $(LIBDIR) clean

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a

re:	fclean all

run:
	./$(NAME) $(INPT)

rerun: re run

dbg: libmake
	$(CC) -g $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)
	lldb $(NAME) $(INPT)