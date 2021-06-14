# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 12:07:35 by bamghoug          #+#    #+#              #
#    Updated: 2021/06/14 12:09:38 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wextra -Wall

# SRCS = ./*.c

all : $(NAME)

$(NAME): 
	cd libft && make
	gcc $(FLAGS) ./libft/libft.a push_swap.c

clean :
	cd libft make clean

fclean : clean
	cd libft make fclean
	rm -rf $(NAME)

re : fclean all
