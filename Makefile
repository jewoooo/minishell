# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 23:57:57 by jewlee            #+#    #+#              #
#    Updated: 2024/06/17 02:38:31 by jewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -lreadline
RM = rm -f
MAKE_CUR = make -C
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
SRCS = ./main.c \
	./parsing/parser.c \
	./parsing/quotes.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -L./libft -lft -I./includes

all : $(NAME)

$(NAME) : make_mandatory

make_mandatory : $(OBJS)
	$(MAKE_CUR) $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@ touch make_mandatory

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE_CUR) $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	@ $(RM) make_mandatory

fclean : clean
	$(MAKE_CUR) $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
