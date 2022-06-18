# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 04:37:57 by yelgharo          #+#    #+#              #
#    Updated: 2022/06/17 15:30:06 by yelgharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_cub3d.a

GREEN = \x1b[32m

define CUB
 			!! CuB3D !!
endef
export CUB

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC := main.c tools_00.c tools_01.c get_map.c get_next_line.c \
	map_element_00.c check_map.c

OBJ := $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $<

$(NAME): text $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o cub3d
	
clean : 
	@rm -f $(OBJ) cub3d
	

fclean : clean
	@rm -f $(NAME)

re : fclean all

text :
	@echo " ${GREEN} $${CUB}"

.PHONY : clean fclean re