/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:39:35 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:39:37 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*g_tabfunc[8])(t_list*) = {
	ft_echo,
	ft_cd,
	ft_pwd,
	ft_export,
	ft_unset,
	ft_env,
	ft_exit,
};

char	**ft_bi_list(void)
{
	int		i;
	char	**bis;

	i = -1;
	bis = malloc(sizeof(char *) * 8);
	if (bis == NULL)
		return (NULL);
	bis[0] = ft_strdup("echo");
	bis[1] = ft_strdup("cd");
	bis[2] = ft_strdup("pwd");
	bis[3] = ft_strdup("export");
	bis[4] = ft_strdup("unset");
	bis[5] = ft_strdup("env");
	bis[6] = ft_strdup("exit");
	bis[7] = NULL;
	while (++i < 7)
	{
		if (bis[i] == NULL)
		{
			ft_freetab(bis);
			return (NULL);
		}
	}
	return (bis);
}

int	is_a_built_in(t_cli *cli)
{
	char	**bi_list;
	int		i;
	t_list	*dup_cmd;

	i = -1;
	bi_list = ft_bi_list();
	if (bi_list == NULL)
		return (-1);
	while (bi_list[++i] != NULL)
	{
		if (ft_strcmp(bi_list[i], cli->cmd->token) == 0)
			break ;
	}
	ft_freetab(bi_list);
	if (i == 7)
		return (0);
	else if (i == 6)
	{
		dup_cmd = lst_dup(cli->cmd->next);
		return (g_tabfunc[i](dup_cmd));
	}
	else
		return (g_tabfunc[i](cli->cmd->next));
	return (0);
}
