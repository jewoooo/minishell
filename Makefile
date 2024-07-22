# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 23:57:57 by jewlee            #+#    #+#              #
#    Updated: 2024/07/23 00:34:55 by jewlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		minishell
CC 				= 		cc
CFLAGS 			= 		-Wall -Wextra -Werror

#RDFLAGS 		= 		-lreadline
# for M2
RDPATH 			= 		-I /opt/homebrew/opt/readline/include
RDFLAGS 		= 		-lreadline $(RDPATH) -L/opt/homebrew/opt/readline/lib

SRCS			=		./srcs/minishell.c						\
						./srcs/0_init/envp.c 					\
						./srcs/0_init/info.c 					\
						./srcs/0_init/signal.c 					\
						./srcs/1_tokenizing/token.c				\
						./srcs/1_tokenizing/tokenizer.c			\
						./srcs/1_tokenizing/valid.c				\
						./srcs/1_tokenizing/env.c				\
						./srcs/1_tokenizing/method.c			\
						./srcs/1_tokenizing/utils.c				\
						./srcs/2_parsing/cmd.c					\
						./srcs/2_parsing/file.c					\
						./srcs/2_parsing/parser.c				\
						./srcs/2_parsing/valid.c				\
						./srcs/2_parsing/init/init.c			\
						./srcs/2_parsing/init/utils.c			\
						./srcs/3_executing/heredoc.c			\
						./srcs/3_executing/executor.c			\
						./srcs/3_executing/path.c				\
						./srcs/3_executing/run.c				\
						./srcs/3_executing/set_fd.c				\
						./srcs/3_executing/set_redirect.c		\
						./srcs/3_executing/valid.c				\
						./srcs/3_executing/clear.c				\
						./srcs/4_builtins/builtins.c			\
						./srcs/4_builtins/pwd.c					\
						./srcs/4_builtins/env.c					\
						./srcs/4_builtins/cd.c					\
						./srcs/4_builtins/exit.c				\
						./srcs/4_builtins/echo.c				\
						./srcs/4_builtins/unset.c				\
						./srcs/4_builtins/export/export.c		\
						./srcs/4_builtins/export/utils.c		\


OBJ				=		$(SRCS:.c=.o)

INCLUDES = -L./libft -lft -I./includes

LIBFT_DIR		=		./libft
#LIBFT_ARC		=		./libft/libft.a

### COLOR CODE ###
NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;
###################

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(CURSIVE)$(YELLOW) "		- Making $(NAME) -" $(NONE)
	@make -C $(LIBFT_DIR) bonus
	@$(CC) $(RDFLAGS) $^ -o $@ $(INCLUDES)
	@echo $(CURSIVE)$(YELLOW) "		- Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "		- Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "		- Making object files -" $(NONE)
	@$(CC) -c $< -o $@ $(RDFLAGS)

dclean :
	@rm -rf ./a.out ./a.out.dSYM

clean :
	@rm -rf $(OBJ)
	@echo $(CURSIVE)$(BLUE) "		- clean OBJ files -" $(NONE)

fclean : clean
	@rm -rf $(NAME)
	@echo $(CURSIVE)$(PURPLE)"		- clean $(NAME) file -"$(NONE)

re  :
	@make fclean
	@make all

.PHONY: all make clean fclean re
