# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 21:54:04 by ysantos-          #+#    #+#              #
#    Updated: 2022/03/01 22:06:41 by ysantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

SRC = *.c

all: $(NAME)

$(NAME):
	gcc -c -o $(NAME) $(SRC)

lib: $(NAME)
	ar rc $(NAME) *.o
	
ran: lib
	ranlib $(NAME).a
	
clean:
	/bin/rm -f $ *.o
	
fclean: clean
	bin/rm -f $(NAME)
	
re: fclean all