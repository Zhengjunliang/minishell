/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:16:46 by juzheng           #+#    #+#             */
/*   Updated: 2023/06/25 16:16:47 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_skip_space(const char *str, int *i);

char	*ft_strdup(const char *s1);
char	*ft_stchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

void	*ft_memdel(void *ptr);

int	get_next_line(int fd, char **line);

#endif
