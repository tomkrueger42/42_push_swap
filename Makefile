# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:28:19 by tkruger           #+#    #+#              #
#    Updated: 2021/12/14 01:00:49 by tomkrueger       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		general
# **************************************************************************** #

#INPT = "4 67 100000 3 87 23 1000 -10000 10 2"
#INPT = "10 17 1 16 7 5 20 18 19 15 9 3 6 0 12 2 4 11 14 8 13"
INPT = "`ruby -e "puts (0..7).to_a.shuffle.join(' ')"`"
NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -o

# **************************************************************************** #
#		SRC
# **************************************************************************** #

SRC = ./src/push_swap.c ./src/list_handling.c ./src/operations.c ./src/lis.c\
		./src/sort.c ./src/merge.c ./src/print.c

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
	bash check.sh

rerun: re run

dbg: libmake
	$(CC) -g $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)
	lldb $(NAME) $(INPT)

check:
	bash check.sh

recheck: re check