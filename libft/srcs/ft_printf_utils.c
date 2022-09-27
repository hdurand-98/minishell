/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:18:03 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/11 14:55:54 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_flag_x_to_maj(t_printf *count, char *str)
{
	int	i;

	i = 0;
	if (count->flag != 'X')
		return ;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		++i;
	}
}

void	ft_strcat_c(t_printf *count, char const c)
{
	int		i;

	i = 0;
	if (where_is_c(count->flag, "c") >= 0 && c == '\0')
	{
		write(1, count->buffer, ft_strlen(count->buffer));
		ft_bzero(count->buffer, ft_strlen(count->buffer));
		write(1, &c, 1);
		++count->return_value;
		return ;
	}
	while (count->buffer[i])
		++i;
	count->buffer[i] = c;
	++i;
	count->buffer[i] = '\0';
	++count->return_value;
}

void	ft_strcat_struct(t_printf *count, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (count->buffer[i])
		++i;
	while (str[j])
	{
		++count->return_value;
		count->buffer[i] = str[j];
		++i;
		++j;
	}
	count->buffer[i] = '\0';
	free(str);
}

static	void	ft_write_space(t_printf *count, char c)
{
	int		i;

	i = 0;
	while (i < count->width_value - 1)
	{
		write(1, &c, 1);
		++count->return_value;
		++i;
	}
}

void	ft_write_buffer_c(t_printf *count, char c)
{
	char	space;

	space = ' ';
	write(1, count->buffer, ft_strlen(count->buffer));
	ft_bzero(count->buffer, ft_strlen(count->buffer));
	if (count->is_minus == 1)
	{
		write(1, &c, 1);
		ft_write_space(count, space);
	}
	else
	{
		ft_write_space(count, space);
		write(1, &c, 1);
	}
	++count->return_value;
}
