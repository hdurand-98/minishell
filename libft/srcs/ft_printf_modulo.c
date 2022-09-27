/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:20:14 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:07:13 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_minus(t_printf *count)
{
	int	len;

	len = 1;
	ft_cpy_buffer(count, "%");
	while (len < count->width_value)
	{
		ft_cpy_buffer(count, " ");
		++len;
	}
}

void	ft_modulo(t_printf *count)
{
	int	len;

	len = 1;
	if (count->is_minus)
	{
		ft_minus(count);
		return ;
	}
	if (count->is_width)
	{
		while (len < count->width_value)
		{
			if (count->is_zero)
				ft_cpy_buffer(count, "0");
			else
				ft_cpy_buffer(count, " ");
			++len;
		}
	}
	ft_cpy_buffer(count, "%");
}
