/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 16:33:50 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/11 14:53:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_buffer(t_printf *count, size_t *j)
{
	write(1, count->buffer, ft_strlen(count->buffer));
	ft_bzero(count->buffer, 1024);
	*j = 0;
	return ;
}

void	ft_cpy_buffer(t_printf *count, char *str)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(count->buffer);
	while (str[i])
	{
		if (j >= 1023)
			ft_init_buffer(count, &j);
		++count->return_value;
		count->buffer[j] = str[i];
		++j;
		++i;
	}
	count->buffer[j] = '\0';
	return ;
}
