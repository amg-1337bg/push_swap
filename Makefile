# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:07:35 by bamghoug          #+#    #+#              #
#    Updated: 2021/06/23 20:33:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wextra -Wall

SRCS = instructions.c instructions1.c linked_list.c \
		push_swap.c sort.c start_sorting.c utils.c \
		utils1.c utils2.c

all : $(NAME)

$(NAME): $(SRCS)
	cd libft && make
	gcc $(FLAGS) $(SRCS) ./libft/libft.a -o $(NAME)

clean :
	cd libft && make clean

fclean : clean
	cd libft && make fclean
	rm -rf $(NAME)

re : fclean all
