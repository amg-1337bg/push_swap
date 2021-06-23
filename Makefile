# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:07:35 by bamghoug          #+#    #+#              #
#    Updated: 2021/06/23 14:59:58 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wextra -Wall

SRCS = *.c

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
