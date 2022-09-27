/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_width_ptr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 12:59:41 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:11:49 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_end(t_printf *count, unsigned long long int nb, int len)
{
	int	end;

	end = 0;
	if (nb == 0 && count->is_precision_without_value == 0)
		len = 3;
	if (count->is_precision)
		if (count->precision_value >= len)
			len = count->precision_value;
	if (nb == 0 && (count->is_precision_without_value
			|| (count->is_precision && count->precision_value == 0)))
		len = 2;
	if (count->width_value > len)
		end = count->width_value - len;
	if (nb == 0 && (count->is_precision_without_value
			|| (count->is_precision && count->precision_value == 0)))
		len = 2;
	return (end);
}

void	ft_do_width_ptr(t_printf *count,
	unsigned long long int nb, int len)
{
	int	end;

	end = ft_end(count, nb, len);
	if (count->is_zero && count->is_minus)
		count->is_zero = 0;
	while (end > 0)
	{
		if (count->is_zero && count->is_precision == 0)
			ft_cpy_buffer(count, "0");
		else
			ft_cpy_buffer(count, " ");
		--end;
	}
}
