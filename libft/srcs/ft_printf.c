/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:47 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:09:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

static	int	ft_convert(va_list *ap, t_printf *count, char *str)
{
	count->sign_is_minus = 0;
	count->is_zero = 0;
	count->is_space = 0;
	count->is_minus = 0;
	count->is_plus = 0;
	count->is_diese = 0;
	count->is_width = 0;
	count->is_precision = 0;
	count->width_value = 0;
	count->precision_value = 0;
	count->is_precision_without_value = 0;
	if (ft_check_convert(count, str) <= 0)
		return (-1);
	if (ft_get_convert(ap, count, str) <= 0)
		return (-1);
	return (0);
}

static	int	ft_cpy_convert(va_list *ap,
	t_printf *count, char const *str, size_t *i)
{
	size_t		j;

	j = 0;
	ft_bzero(count->convert, 128);
	while (str && str[*i] && (where_is_c(str[*i], INDEX_FLAG)) < 0)
	{
		if (j >= 127)
		{
			count->convert[j] = '\0';
			if (ft_convert(ap, count, (char *)count->convert))
				return (-1);
			ft_bzero(count->convert, 128);
			j = 0;
		}
		count->convert[j] = str[*i];
		++j;
		++*i;
	}
	count->convert[j] = '\0';
	if (ft_convert(ap, count, (char *)count->convert))
		return (-1);
	return (0);
}

static	int	ft_conversion(va_list *ap, t_printf *count, char c)
{
	int		ret;
	int		(*ft_flag[8])(t_printf *count, va_list *ap);

	(ft_flag[0]) = &ft_int;
	(ft_flag[1]) = &ft_int;
	(ft_flag[2]) = &ft_int_base;
	(ft_flag[3]) = &ft_int_base;
	(ft_flag[4]) = &ft_int_base;
	(ft_flag[5]) = &ft_char;
	(ft_flag[6]) = &ft_string;
	(ft_flag[7]) = &ft_ptr;
	count->flag = c;
	ret = where_is_c(c, INDEX_FLAG);
	if (ret < 0)
		return (-1);
	if (ret == 8)
	{
		ft_modulo(count);
		return (0);
	}
	if (((*ft_flag[ret])(count, ap)))
		return (-1);
	return (0);
}

static	int	ft_parsing(t_printf *count, va_list *ap, const char *str)
{
	size_t		i;

	i = 0;
	count->return_value = 0;
	ft_bzero(count->buffer, 1024);
	while (str && str[i])
	{
		if (i != 0 && str[i - 1] == '%')
		{
			if (ft_cpy_convert(ap, count, str, &i))
				return (-1);
			if ((ft_conversion(ap, count, str[i])))
				return (-1);
			++i;
		}
		if (str[i] != '%' && str[i])
			ft_strcat_c(count, str[i]);
		if (str[i])
			++i;
	}
	write(1, count->buffer, ft_strlen(count->buffer));
	return (count->return_value);
}

int	ft_printf(const char *str, ...)
{
	t_printf	count;
	va_list		ap;
	int			ret;

	ret = 0;
	count.return_value = 0;
	count.flag = 0;
	va_start(ap, str);
	ret = ft_parsing(&count, &ap, str);
	if (ret < 0)
		return (-1);
	va_end(ap);
	return (ret);
}
