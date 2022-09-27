/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_width_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 13:34:55 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:13:45 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_end(t_printf *count, long int nb, int len)
{
	int	end;

	end = 0;
	if (count->is_precision)
	{
		if (count->precision_value >= len)
		{
			if (nb < 0 || (count->is_minus && count->sign_is_minus))
				len = count->precision_value + 1;
			else
				len = count->precision_value;
		}
	}
	if (count->width_value > len)
		end = count->width_value - len;
	if (nb == 0 && (count->is_precision_without_value
			|| (count->is_precision && count->precision_value == 0)))
		++end;
	return (end);
}

int	ft_do_width_int(t_printf *count, long int nb, int len)
{
	int	end;
	int	sign;

	sign = 1;
	end = ft_end(count, nb, len);
	if (count->is_zero && count->is_minus)
		count->is_zero = 0;
	if (nb < 0 && count->is_zero && count->is_precision == 0
		&& count->is_precision_without_value == 0)
	{
		ft_cpy_buffer(count, "-");
		sign = (-1);
	}
	while (end > 0)
	{
		if (count->is_zero && count->is_precision == 0
			&& count->is_precision_without_value == 0)
			ft_cpy_buffer(count, "0");
		else
			ft_cpy_buffer(count, " ");
		--end;
	}
	return (sign);
}
