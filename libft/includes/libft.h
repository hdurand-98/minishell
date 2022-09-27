/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:06:03 by tallaire          #+#    #+#             */
/*   Updated: 2021/04/07 13:12:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf.h"

# define BUFFER_SIZE	1024

enum		e_bool
{
	YES	= 0,
	NO	= (-1)
};

/*
** ##############################
** ########### LIBFT ############
** ##############################
*/

void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
long	long		ft_atoll(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, char const *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strldup(char *str, size_t size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(char const *str, char c);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

/*
** #####################################
** ############## GNL ##################
** #####################################
*/

int				get_next_line(int fd, char **line);
int				ft_strlen_gnl(char *str);
int				is_to_c(char *str, int c);
int				ft_error(char **s1, char **s2);

/*
** #####################################
** ########## MY FUNCTIONS #############
** #####################################
*/

int				c_is_alnum(int c);
int				c_is_str(int c, char *str);
int				where_is_c(int c, char *str);
void			free_get_file(char **txt);
void			print_binary(long long int value, int nb_octet);
char			**ft_split_slash(char *str, char *sep);

#endif
