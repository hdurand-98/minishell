/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:05:44 by user42            #+#    #+#             */
/*   Updated: 2021/09/16 10:40:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	remove_first_var(t_list *tmp)
{
	free(g_glob.env->name);
	free(g_glob.env->value);
	g_glob.env = g_glob.env->next;
	free(tmp);
	return ;
}

static	void	remove_var(char *str)
{
	t_list	*prev;
	t_list	*tmp;

	tmp = g_glob.env;
	if (ft_strcmp(str, g_glob.env->name) == YES)
		return (remove_first_var(tmp));
	while (g_glob.env)
	{
		if (ft_strcmp(str, g_glob.env->name) == YES)
		{
			free(g_glob.env->name);
			free(g_glob.env->value);
			prev->next = g_glob.env->next;
			free(g_glob.env);
			g_glob.env = tmp;
			return ;
		}
		prev = g_glob.env;
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
}

static	int	is_var_valid(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '_' && c_is_alnum(str[i]) == NO)
		{
			ft_putstr_fd("minishell: unset : \" ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(" \" invalid username\n", 2);
			g_glob.ret = 1;
			break ;
		}
		++i;
	}
	if (str[0] == '\0' || (str[0] >= '0' && str[0] <= '9'))
	{
		ft_putstr_fd("minishell: unset : \" ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" \" invalid username\n", 2);
		g_glob.ret = 1;
	}
	return (YES);
}

static	void	do_unset(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (is_var_valid(cmd->token) == YES)
			remove_var(cmd->token);
		cmd = cmd->next;
	}
	cmd = tmp;
}

int	ft_unset(t_list *cmd)
{
	g_glob.ret = 0;
	if (cmd == NULL)
	{
		g_glob.ret = 0;
		return (1);
	}
	else
		do_unset(cmd);
	return (1);
}
