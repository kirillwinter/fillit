# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wballaba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:32:16 by wballaba          #+#    #+#              #
#    Updated: 2018/12/15 17:32:18 by wballaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/main.c srcs/fillit.c srcs/read_fillit.c

INCLUDES = includes

all: $(NAME)

$(NAME):
	@gcc -g -Wall -Werror -Wextra $(SRCS) -o $(NAME) -L libft/ -lft -I libft/includes/ -I includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
