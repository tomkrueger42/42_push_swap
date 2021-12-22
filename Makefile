# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:28:19 by tkruger           #+#    #+#              #
#    Updated: 2021/12/21 23:45:06 by tkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		general
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -o

# **************************************************************************** #
#		SRC
# **************************************************************************** #

SRC = ./src/push_swap.c ./src/operations.c ./src/operation_utils.c ./src/sort.c\
		./src/efficient_rotation.c ./src/utils.c ./src/print.c

# **************************************************************************** #
#		Libs
# **************************************************************************** #

LIBDIR = libs/libft
LIB = -L./$(LIBDIR) -lft
INC = -I./$(LIBDIR)
# for LIB: either -l:libft.a or -lft same same

# **************************************************************************** #
#		rules
# **************************************************************************** #

$(NAME): libmake
	$(CC) $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)

all: $(NAME)

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

dbg: libmake
	$(CC) -g $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)
	lldb $(NAME) "`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`"

asan:
	$(CC) -fsanitize=address -static-libsan -fno-omit-frame-pointer $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)
	bash check.sh

check:
	bash check.sh

recheck: re check