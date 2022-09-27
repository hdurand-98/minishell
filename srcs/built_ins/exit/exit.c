/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:31 by user42            #+#    #+#             */
/*   Updated: 2021/09/16 10:38:47 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	our_exit(int ret)
{
	t_list	*tmp;

	while (g_glob.env)
	{
		free(g_glob.env->name);
		free(g_glob.env->value);
		tmp = g_glob.env;
		g_glob.env = g_glob.env->next;
		free(tmp);
	}
	if (g_glob.head != NULL)
		free_cli(g_glob.head);
	exit(ret);
	return (1);
}

static	int	set_ret_value(char *str)
{
	unsigned char	ret_char;
	long long		ret;

	ret = ft_atoll(str);
	ret_char = (unsigned char)ret;
	g_glob.ret = (int)ret_char;
	free(str);
	return ((int)ret_char);
}

int	valid_num_of_arg(char *str)
{
	if (is_arg_exit_valid(str) == NO)
	{
		free(str);
		return (our_exit(255));
	}
	our_exit(set_ret_value(str));
	return (1);
}

int	ft_exit(t_list *cmd)
{
	size_t	size;
	char	*str;

	if (g_glob.ispipe == 0)
		write(2, "exit\n", 5);
	size = lst_size(cmd);
	if (size > 1)
	{
		lst_free(cmd);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_glob.ret = 1;
	}
	else if (size == 1)
	{
		str = ft_strdup(cmd->token);
		lst_free(cmd);
		valid_num_of_arg(str);
	}
	else
	{
		lst_free(cmd);
		our_exit(0);
	}
	return (1);
}
