/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 18:09:45 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:06:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_len(unsigned long long int n)
{
	int						len;
	unsigned long long int	nb;

	len = 0;
	nb = n;
	while (nb)
	{
		nb /= 16;
		++len;
	}
	len = len + 2;
	return (len);
}

static	void	ft_do_precision_ptr(t_printf *count, int len)
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

static	void	ft_cpy_buffer_ptr(t_printf *count, unsigned long long int nb)
{
	int		len;
	char	buff[13];
	char	base[17];

	if (nb == 0 && count->is_width == 0
		&& (count->is_precision || count->is_precision_without_value))
		return ;
	ft_bzero(buff, 13);
	ft_bzero(base, 17);
	ft_strcpy(base, "0123456789abcdef");
	len = ft_len(nb) - 2;
	if (nb == 0)
		len = 1;
	buff[len] = '\0';
	while (len)
	{
		--len;
		buff[len] = base[nb % 16];
		nb = nb / 16;
	}
	ft_cpy_buffer(count, buff);
}

static	void	ft_do_convert_ptr(t_printf *count,
	unsigned long long int nb, int len)
{
	if (count->is_minus)
	{
		ft_cpy_buffer(count, "0x");
		if (count->is_precision && count->precision_value != 0)
			count->precision_value += 2;
		if ((count->is_precision && count->precision_value != 0)
			&& (count->is_precision == 0 || count->precision_value != 0))
			ft_do_precision_ptr(count, len);
		if (count->is_precision_without_value == 0 || nb != 0)
			ft_cpy_buffer_ptr(count, nb);
		if (count->is_width)
			ft_do_width_ptr(count, nb, len);
		return ;
	}
	if (count->is_precision && count->precision_value != 0)
		count->precision_value += 2;
	if (count->is_width)
		ft_do_width_ptr(count, nb, len);
	ft_cpy_buffer(count, "0x");
	if (count->is_precision && count->precision_value != 0)
		ft_do_precision_ptr(count, len);
	if (count->is_precision_without_value == 0 || nb != 0)
		ft_cpy_buffer_ptr(count, nb);
}

int	ft_ptr(t_printf *count, va_list *ap)
{
	unsigned long long int	nb;
	int						len;

	nb = 0;
	len = 0;
	nb = (unsigned long long int)va_arg(*ap, void *);
	len = ft_len(nb);
	ft_do_convert_ptr(count, nb, len);
	return (0);
}
