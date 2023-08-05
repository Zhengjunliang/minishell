# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzheng <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:49:02 by juzheng           #+#    #+#              #
#    Updated: 2023/06/21 14:49:03 by juzheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I includes/

FILES	=	ft_putstr_fd ft_strdup get_next_line ft_memdel ft_putendl_fd \
			ft_strchr ft_strcmp ft_putendl ft_strjoin ft_itoa \
			ft_calloc ft_bzero ft_strlen ft_strncmp \
			ft_lstadd_front ft_lstnew ft_split

SRCS	=	$(addsuffix .c, $(addprefix srcs/, $(FILES)))

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f


all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "\n\n\033[0;32mCompiling libft..."
	@ar rc $(NAME) $^
	@echo "\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
