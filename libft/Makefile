# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 09:56:17 by ofrost-g          #+#    #+#              #
#    Updated: 2019/05/02 17:27:17 by ofrost-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all :	$(NAME)

$(NAME)	:
	gcc -c -Wall -Wextra -Werror ./*.c -I ./libft.h
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean :
	/bin/rm -f *.o

fclean :	clean
	/bin/rm -f $(NAME) *.o

re :	fclean all
