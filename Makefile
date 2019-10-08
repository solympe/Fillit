# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slenore <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:03:30 by slenore           #+#    #+#              #
#    Updated: 2019/10/02 21:27:36 by slenore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS =  -Wall -Wextra -Werror
LIB = libft.a
VPATH =srcs

FUNCTIONS = ft_sqrt  map packer tetromaker reader get_next_line 
SRC =  $(patsubst  %,srcs/%.c, $(FUNCTIONS))
OBJECTS   =  $(patsubst %, %.o , $(FUNCTIONS))

.PHONY: all fclean clean re relib




all: $(NAME)

$(NAME): 
	@make re -C libft	
	@clang $(CFLAGS) -c $(SRC)  -I libft/ -I srcs/
	@clang $(CFLAGS) $(OBJECTS) -I  libft/  -L. -lft -o $(NAME)
clean:
	rm -f $(OBJECTS) 
	make clean -C libft

fclean: clean 
	@rm -f $(NAME) $(LIB)
	
re: fclean all
	
relib:
	make re -C libft
