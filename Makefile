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
CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

MAIN	=	minishell

SRC 	=	$(addsuffix .c, $(addprefix srcs/main/, $(MAIN)))

OBJS	=	$(SRC:.c=.o)
RM		=	rm -f

all:	$(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I includes/

$(NAME):	$(OBJS)
	@make -C libft/
	@echo	"\033[0;32mCompiling minishell..."
	@$(CC)	$(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME) $(all)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
