/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_convert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:43:39 by tallaire          #+#    #+#             */
/*   Updated: 2020/03/12 16:15:45 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_check_convert_attribut(t_printf *count, char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '.' && (str[i] <= '0' || str[i] > '9')
		 && str[i] != '*')
	{
		if (str[i] == '#')
			count->is_diese = 1;
		if (str[i] == '0')
			count->is_zero = 1;
		if (str[i] == '-')
			count->is_minus = 1;
		if (str[i] == '+')
			count->is_plus = 1;
		if (str[i] == ' ')
			count->is_space = 1;
		if (where_is_c(str[i], "#0-+ ") < 0)
			return (-1);
		++i;
	}
	return (1);
}

static	int	ft_check_convert_width(t_printf *count, char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '.' && (str[i] <= '0' || str[i] > '9')
		&& str[i] != '*')
		++i;
	if (str[i] == '*' || (str[i] > '0' && str[i] <= '9'))
		count->is_width = 1;
	while (str && str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
			++i;
		else if (str[i] == '*')
			++i;
		else
			return (-1);
	}
	return (1);
}

static	int	ft_check_convert_precision(t_printf *count, char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '.')
		++i;
	if (str[i] == '.')
	{
		++i;
		if (str[i] == '*' || (str[i] >= '0' && str[i] <= '9'))
			count->is_precision = 1;
		else
			count->is_precision_without_value = 1;
	}
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			++i;
		else if (str[i] == '*')
			++i;
		else
			return (-1);
	}
	return (1);
}

int	ft_check_convert(t_printf *count, char *str)
{
	count->is_diese = 0;
	count->is_plus = 0;
	count->is_minus = 0;
	count->is_space = 0;
	count->is_zero = 0;
	count->is_precision = 0;
	count->is_width = 0;
	count->is_precision_without_value = 0;
	if (ft_check_convert_attribut(count, str) <= 0)
		return (-1);
	if (ft_check_convert_width(count, str) <= 0)
		return (-1);
	if (ft_check_convert_precision(count, str) <= 0)
		return (-1);
	return (1);
}
