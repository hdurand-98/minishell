/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:02:09 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:11:01 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_len_start_width(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && (str[i] <= '0' || str[i] > '9') && str[i] != '.'
		&& str[i] != '*')
		++i;
	return (i);
}

static	int	ft_len_start_precision(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i - 1] != '.')
		++i;
	return (i);
}

static	int	ft_get_width(va_list *ap, t_printf *count, char *str)
{
	int		i;

	i = ft_len_start_width(str);
	while (str[i] && str[i] != '.')
	{
		while (str && (str[i] >= '0' && str[i] <= '9'))
		{
			count->width_value *= 10;
			count->width_value += str[i] - '0';
			++i;
		}
		while (str && str[i] == '*')
		{
			count->width_value = va_arg(*ap, int);
			if (count->width_value < 0)
			{
				count->is_minus = 1;
				count->width_value *= (-1);
			}
			++i;
		}
	}
	return (1);
}

static	int	ft_get_precision(va_list *ap, t_printf *count, char *str)
{
	int		i;

	i = ft_len_start_precision(str);
	while (str && str[i])
	{
		count->precision_value = 0;
		while (str && str[i] >= '0' && str[i] <= '9')
		{
			count->precision_value *= 10;
			count->precision_value += str[i++] - '0';
		}
		while (str && str[i++] == '*')
		{
			count->precision_value = va_arg(*ap, int);
			if (count->precision_value < 0)
			{
				count->precision_value = 0;
				count->is_precision = 0;
			}
		}
	}
	return (1);
}

int	ft_get_convert(va_list *ap, t_printf *count, char *str)
{
	count->width_value = 0;
	count->precision_value = 0;
	if (ft_get_width(ap, count, str) <= 0)
		return (-1);
	if (ft_get_precision(ap, count, str) <= 0)
		return (-1);
	return (1);
}
