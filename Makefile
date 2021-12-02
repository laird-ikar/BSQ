# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 08:45:27 by bguyot            #+#    #+#              #
#    Updated: 2021/11/30 09:36:22 by bdehais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = bsq.c check_empty_square.c check_map_rules.c find_big_square.c get_corners.c re_map_to_machinable_things.c
FLAGS = -Wall -Wextra -Werror

all: bsq

bsq:
	clear
	gcc $(FLAGS) -o bsq $(SRC)

clean:
	rm -f bsq

re: clean bsq
