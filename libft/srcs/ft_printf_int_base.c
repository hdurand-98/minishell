/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 14:06:32 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:13:21 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_len(t_printf *count, unsigned long int n)
{
	unsigned long int	nb;
	int					len;
	unsigned long int	base;

	nb = n;
	len = 0;
	if (count->flag == 'u')
		base = 10;
	else if (count->flag == 'x' || count->flag == 'X')
		base = 16;
	else
		return (-1);
	if (nb == 0 && count->is_precision_without_value == 0
		&& (!(count->is_precision && count->precision_value == 0)))
		return (1);
	while (nb)
	{
		nb /= base;
		++len;
	}
	return (len);
}

static	void	ft_do_precision_int_base(t_printf *count, int len)
{
	int	end;

	end = 0;
	if (count->precision_value > len)
		end = count->precision_value - len;
	while (end)
	{
		ft_cpy_buffer(count, "0");
		--end;
	}
}

static	void	ft_cpy_buffer_int_base(t_printf *count,
unsigned long int nb, int len)
{
	unsigned long int		base;
	char					buff[30];
	char					base_hexa[17];

	ft_bzero(buff, 30);
	ft_bzero(base_hexa, 17);
	if (count->flag == 'u')
		base = 10;
	else
		base = 16;
	if (count->flag == 'u')
		ft_strcpy(base_hexa, "0123456789");
	else if (count->flag == 'x')
		ft_strcpy(base_hexa, "0123456789abcdef");
	else
		ft_strcpy(base_hexa, "0123456789ABCDEF");
	buff[len] = '\0';
	while (len)
	{
		--len;
		buff[len] = base_hexa[nb % base];
		nb = nb / base;
	}
	ft_cpy_buffer(count, buff);
}

static	void	ft_do_convert_int_base(t_printf *count,
unsigned long int nb, int len)
{
	if (count->is_minus)
	{
		if (count->is_precision)
			ft_do_precision_int_base(count, len);
		if (!(nb == 0 && (count->is_precision_without_value
					|| (count->is_precision && count->precision_value == 0))))
			ft_cpy_buffer_int_base(count, nb, len);
		if (count->is_width)
			ft_do_width_int_base(count, len);
		return ;
	}
	if (count->is_width)
		ft_do_width_int_base(count, len);
	if (count->is_precision)
		ft_do_precision_int_base(count, len);
	if (!(nb == 0 && (count->is_precision_without_value
				|| (count->is_precision && count->precision_value == 0))))
		ft_cpy_buffer_int_base(count, nb, len);
}

int	ft_int_base(t_printf *count, va_list *ap)
{
	unsigned long int		nb;
	int						len;

	nb = 0;
	len = 0;
	nb = (unsigned long int)va_arg(*ap, unsigned int);
	len = ft_len(count, nb);
	if (len < 0)
		return (-1);
	ft_do_convert_int_base(count, nb, len);
	return (0);
}
