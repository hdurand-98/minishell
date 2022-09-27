/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 11:55:34 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:02:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_precision(t_printf *count, char *str)
{
	int		i;
	int		end;
	size_t	j;

	if (count->is_precision_without_value)
		return ;
	i = 0;
	j = ft_strlen(count->buffer);
	if (count->is_precision
		&& count->precision_value < (int)ft_strlen(str))
		end = count->precision_value;
	else
		end = (int)ft_strlen(str);
	while (str && i < end)
	{
		if (j >= 1023)
			ft_init_buffer(count, &j);
		count->buffer[j] = str[i];
		++count->return_value;
		++j;
		++i;
	}
	count->buffer[j] = '\0';
}

static	int	ft_minus(t_printf *count, char *str)
{
	int		len;
	int		end;

	end = 0;
	len = 0;
	if (count->is_width)
		end = count->width_value;
	if ((count->precision_value > (int)ft_strlen(str)
			|| count->is_precision == 0)
		&& count->is_precision_without_value == 0)
		len = (int)ft_strlen(str);
	else if (count->is_precision_without_value == 0)
		len = count->precision_value;
	ft_precision(count, str);
	while (str && len < end)
	{
		ft_cpy_buffer(count, " ");
		++len;
	}
	return (1);
}

static	int	ft_do_convert_string(t_printf *count, char *str)
{
	int		len;
	int		end;

	end = 0;
	len = 0;
	if (count->is_minus)
		return (ft_minus(count, str));
	if (count->is_precision
		&& count->precision_value < (int)ft_strlen(str))
		len = count->precision_value;
	else if (count->is_precision_without_value == 0)
		len = (int)ft_strlen(str);
	if (count->is_width && count->width_value > len)
		end = count->width_value;
	while (str && len < end)
	{
		if (count->is_zero)
			ft_cpy_buffer(count, "0");
		else
			ft_cpy_buffer(count, " ");
		++len;
	}
	ft_precision(count, str);
	return (1);
}

int	ft_string(t_printf *count, va_list *ap)
{
	char	*string;

	string = NULL;
	string = va_arg(*ap, char *);
	if (!string)
		return (ft_do_convert_string(count, "(null)"));
	if (ft_do_convert_string(count, string) <= 0)
		return (-1);
	return (0);
}
