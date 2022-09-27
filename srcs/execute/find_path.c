/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:39 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:40:40 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_find_path(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp != NULL && ft_strcmp(tmp->name, "PATH") != 0)
		tmp = tmp->next;
	return (tmp);
}

void	ft_exec_failed(char **env, char **paths, char *str, char **av)
{
	ft_freetab(paths);
	ft_freetab(env);
	ft_putstr_fd(str, 2);
	free(str);
	ft_exit_proc(av, 0);
}

void	ft_free_proc(t_cli *cli)
{
	t_list	*tmp;

	free_cli(cli);
	while (g_glob.env)
	{
		free(g_glob.env->name);
		free(g_glob.env->value);
		tmp = g_glob.env;
		g_glob.env = g_glob.env->next;
		free(tmp);
	}
}

int	ft_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}
