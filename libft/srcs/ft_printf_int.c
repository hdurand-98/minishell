/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:50:14 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:20:14 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_len(long int n)
{
	int			len;
	long int	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
		++len;
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

static	int	ft_do_precision_int(t_printf *count, long int nb, int len)
{
	int	sign;
	int	end;

	end = 0;
	sign = 1;
	if (nb < 0)
	{
		--len;
		ft_cpy_buffer(count, "-");
		sign = (-1);
		count->sign_is_minus = 1;
	}
	if (count->precision_value > len)
		end = count->precision_value - len;
	while (end)
	{
		ft_cpy_buffer(count, "0");
		--end;
	}
	return (sign);
}

static	void	ft_cpy_buffer_int(t_printf *count, long int nb)
{
	int		len;
	int		sign;
	char	buff[30];

	if (nb == 0 && (count->is_precision_without_value
			|| (count->is_precision && count->precision_value == 0)))
		return ;
	ft_bzero(buff, 30);
	len = ft_len(nb);
	sign = 0;
	buff[len] = '\0';
	if (nb < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	while (len)
	{
		--len;
		buff[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (sign)
		buff[0] = '-';
	ft_cpy_buffer(count, buff);
}

static	void	ft_do_convert_int(t_printf *count, long int nb, int len)
{
	int	sign;

	sign = 1;
	if (count->is_minus)
	{
		if (count->is_precision)
			sign = ft_do_precision_int(count, nb, len);
		nb = nb * sign;
		ft_cpy_buffer_int(count, nb);
		if (count->is_width && count->width_value)
			ft_do_width_int(count, nb, len);
		return ;
	}
	if (count->is_width && count->width_value)
		sign = ft_do_width_int(count, nb, len);
	if (count->is_precision)
		sign = ft_do_precision_int(count, nb, len);
	nb = nb * sign;
	ft_cpy_buffer_int(count, nb);
}

int	ft_int(t_printf *count, va_list *ap)
{
	long int		nb;
	int				len;

	nb = 0;
	len = 0;
	nb = va_arg(*ap, int);
	len = ft_len(nb);
	ft_do_convert_int(count, nb, len);
	return (0);
}
