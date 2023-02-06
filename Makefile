# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 18:05:51 by aahrach           #+#    #+#              #
#    Updated: 2023/02/05 20:14:57 by aahrach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC = ./libft/ft_atoi.c ./libft/ft_split.c ./libft/linked_list.c \
	five.c main.c operation.c push_swap.c three.c one_hundred.c five_hundred.c \

SRC_BONUS = checker.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	./libft/linked_list.c ./libft/ft_atoi.c ./libft/ft_split.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
