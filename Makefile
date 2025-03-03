# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 17:25:03 by ofrost-g          #+#    #+#              #
#    Updated: 2019/04/24 21:10:26 by ofrost-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCL_PATH = -I includes/

SRC_PATH = src/
SRC_LIST = calculating_iso.c check.c drawing.c main.c reading.c settings.c utilits.c
SRC = $(addprefix $(SRC_PATH), $(SRC_LIST))

OBJ_PATH = obj/
OBJ_LIST = $(patsubst %.c, %.o,$(SRC_LIST))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_LIST))


CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g

FT		= libft
FT_INC	= -I libft/
FT_LINK	= -L libft/ -lft

MLX&FRAMEWORKS = -lm -lmlx -framework OpenGl -framework Appkit

all: make_obj_path make_ft $(NAME)

make_obj_path:
	mkdir -p $(OBJ_PATH)

make_ft: 
	make -C libft

$(OBJ):
    $(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CCFLAGS) $(FT_INC) $(INCL_PATH) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)


$(NAME): $(OBJ)
	$(CC) $(SRC) $(MLX&FRAMEWORKS) $(FT_LINK) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ)
	make -C $(FT) fclean

re: fclean all
