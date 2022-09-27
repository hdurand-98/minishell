/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:06:54 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:11:23 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define INDEX_FLAG "diuxXcsp%"
# define INDEX_NUM "diuxXp"
# define INDEX_NUM_NO_BASE "di"
# define INDEX_ALPHA "c"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_printf
{
	char		buffer[1024];
	char		convert[128];
	char		flag;
	char		mem[3];
	int			sign_is_minus;
	int			is_zero;
	int			is_space;
	int			is_minus;
	int			is_plus;
	int			is_diese;
	int			is_width;
	int			is_precision;
	int			width_value;
	int			precision_value;
	int			is_precision_without_value;
	int			flag_is_c_0;
	int			return_value;
}				t_printf;

int				ft_printf(char const *str, ...);
int				ft_int(t_printf *count, va_list *ap);
int				ft_int_base(t_printf *count, va_list *ap);
int				ft_ptr(t_printf *count, va_list *ap);
int				ft_string(t_printf *count, va_list *ap);
void			ft_modulo(t_printf *count);
int				ft_check_convert(t_printf *count, char *str);
void			ft_strcat_c(t_printf *count, char const c);
void			ft_strcat_struct(t_printf *count, char *str);
int				ft_get_convert(va_list *ap, t_printf *count, char *str);
int				ft_char(t_printf *count, va_list *ap);
void			ft_write_buffer_c(t_printf *count, char c);
void			ft_cpy_buffer(t_printf *count, char *str);
char			*ft_do_width_string(t_printf *count, char *str);
void			ft_flag_x_to_maj(t_printf *count, char *str);
void			ft_init_buffer(t_printf *count, size_t *j);
int				ft_do_width_int(t_printf *count, long int nb, int len);
void			ft_do_width_ptr(t_printf *count,
					unsigned long long int nb, int len);
void			ft_do_width_int_base(t_printf *count, int len);

#endif
