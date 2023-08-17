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
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_isdigit(int num);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
char	*ft_strdup(const char *s1);
char	*ft_chr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);

#endif
