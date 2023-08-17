# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:47:37 by juzheng           #+#    #+#              #
#    Updated: 2023/06/21 14:47:38 by juzheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I includes/

LIBFT	=	libft/libft.a

BUILTINS	=	exit builtin echo pwd env cd \
				cmdlst cmd_utils

EXEC	=	exec executor

MAIN	=	main free signal init

LEXER	=	lexer list reader_utils reader read_utils2 \
			redirect get_next_line

UTILS	=	ft_split1 ft_countwords1 ft_subsplit \
			ft_trims ft_expander ft_expander2

SRC 	=	$(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS))) \
			$(addsuffix .c, $(addprefix srcs/exec/, $(EXEC))) \
			$(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
			$(addsuffix .c, $(addprefix srcs/lexer/, $(LEXER))) \
			$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \
			$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))

OBJS	=	$(SRC:.c=.o)
RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "\n"
	@make -C libft/
	@echo	"\033[0;32mCompiling minishell..."
	@$(CC)	$(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline
	@echo "\n\033[0mDone!"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@$(RM) $(OBJS)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting object..."
	@$(RM) $(OBJS) $(NAME)
	@echo "\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
