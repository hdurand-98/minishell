/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_width_int_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:00:08 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/17 14:00:09 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_end(t_printf *count, int len)
{
	int	end;

	end = 0;
	if (count->is_precision)
		if (count->precision_value >= len)
			len = count->precision_value;
	if (count->width_value > len)
		end = count->width_value - len;
	return (end);
}

void	ft_do_width_int_base(t_printf *count, int len)
{
	int	end;

	end = ft_end(count, len);
	if (count->is_zero && count->is_minus)
		count->is_zero = 0;
	while (end > 0)
	{
		if (count->is_zero && count->is_precision == 0
			&& count->is_precision_without_value == 0)
			ft_cpy_buffer(count, "0");
		else
			ft_cpy_buffer(count, " ");
		--end;
	}
}
