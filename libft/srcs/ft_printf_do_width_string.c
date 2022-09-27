/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_width_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:12:31 by tallaire          #+#    #+#             */
/*   Updated: 2020/04/20 14:12:31 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_minus_is_yes(t_printf *count, char *str, char *new)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		++i;
	}
	while (i < count->width_value)
	{
		new[i] = ' ';
		++i;
	}
	new[i] = '\0';
}

static	void	ft_minus_is_no(t_printf *count, char *str, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count->width_value - (int)ft_strlen((const char *)str))
	{
		if (count->is_zero)
			new[i] = '0';
		else
			new[i] = ' ';
		++i;
	}
	while (str && i < count->width_value)
	{
		new[i] = str[j];
		++i;
		++j;
	}
	new[i] = '\0';
}

char	*ft_do_width_string(t_printf *count, char *str)
{
	int		len;
	char	*new;

	new = NULL;
	len = (int)ft_strlen((const char *)str);
	if (len >= count->width_value)
		return (str);
	new = malloc(sizeof(char) * (unsigned long int)count->width_value);
	if (!new)
		return (NULL);
	if (count->is_minus)
		ft_minus_is_yes(count, str, new);
	else
		ft_minus_is_no(count, str, new);
	free(str);
	return (new);
}
