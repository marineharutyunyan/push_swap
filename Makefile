# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:15:29 by knikogho          #+#    #+#              #
#    Updated: 2022/09/07 20:00:09 by knikogho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BONUS		= checker

TMP			= tmp

SRCS		= $(shell find . -maxdepth 1 -name '*.c' ! -name '*_bonus.c')

OBJS		= $(patsubst ./%.o, $(TMP)/%.o, $(SRCS:.c=.o))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror 

COPTIONS	= -I.

RM			= rm -rf

all:		$(NAME)

./$(TMP)/%.o: ./%.c
			$(CC) $(CFLAGS) $(COPTIONS) -o $@ -c $<

$(TMP):
			mkdir $(TMP)

$(NAME): 	$(TMP) $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(TMP)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re