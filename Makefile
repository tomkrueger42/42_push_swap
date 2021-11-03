# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:28:19 by tkruger           #+#    #+#              #
#    Updated: 2021/11/03 17:17:47 by tkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INPT = "6 5 4 3 2 1"
NAME = push_swap
FLAGS = -Wall -Werror -Wextra -o
SRC = ./src/push_swap.c ./src/list_handling.c ./src/operations.c
INC = -I./libft
LIB = -L./libft -lft
# for LIB: either -l:libft.a or -lft same same
# will have to copy libft into the intra repo for evaluation!!!

$(NAME): libmake
	gcc $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)

all:	$(NAME)

libmake:
	@make -C ./libft all
	@make -C ./libft clean

clean:
	@rm -f *.o *~
	@make -C ./libft/ clean

fclean:	clean
	@rm -f $(NAME)
	@rm -f ./libft/libft.a

re:	fclean all

run:
	./$(NAME) $(INPT)

rerun: re run

dbg: libmake
	gcc -g $(FLAGS) $(NAME) $(SRC) $(LIB) $(INC)
	lldb $(NAME) $(INPT)