/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:57:58 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/04 19:57:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_arg_name_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || (str[0] >= '0' && str[0] <= '9'))
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : invalid option\n", 2);
		return (NO);
	}
	while (str && str[i])
	{
		if (c_is_alnum(str[i]) == NO && str[i] != '_')
		{
			ft_printf("minishell: export: %s : ", str);
			ft_printf("invalid option\n");
			return (NO);
		}
		++i;
	}
	return (YES);
}

int	check_name_and_value(char *name, char *value)
{
	(void)value;
	if (is_arg_name_valid(name) == NO)
	{
		g_glob.ret = 1;
		free(name);
		return (NO);
	}
	return (YES);
}
