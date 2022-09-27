/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_proc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:39:51 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:39:53 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_double_strjoin(char *str1, char *str2, char *str3)
{
	char	*tmpstr;
	char	*strf;

	tmpstr = NULL;
	strf = NULL;
	tmpstr = ft_strjoin(str1, str2);
	strf = ft_strjoin(tmpstr, str3);
	free(tmpstr);
	return (strf);
}

char	**ft_end_of_tab(char **av, t_list *cmd, int depth)
{
	av = malloc(sizeof(char *) * (depth + 2));
	if (av == NULL)
		return (NULL);
	if (cmd->kind == 0)
	{
		av[depth] = ft_double_strjoin(cmd->name, "=", cmd->value);
		if (av[depth] == NULL)
			return (NULL);
		av[depth + 1] = NULL;
	}
	else
		av[depth] = NULL;
	return (av);
}

char	**ft_env_to_tab(t_list *cmd, int depth)
{
	char	**av;

	av = NULL;
	if (cmd && cmd->next != NULL)
	{
		if (cmd->kind == 0)
		{
			av = ft_env_to_tab(cmd->next, depth + 1);
			av[depth] = ft_double_strjoin(cmd->name, "=", cmd->value);
		}
		else
			av = ft_env_to_tab(cmd->next, depth);
	}
	else if (cmd)
	{
		av = ft_end_of_tab(av, cmd, depth);
		if (av == NULL)
			return (NULL);
	}
	return (av);
}

void	ft_freetab(char **tabl)
{
	int	i;

	i = -1;
	if (tabl == NULL)
		return ;
	while (tabl[++i] != NULL)
		free(tabl[i]);
	free(tabl);
}

void	ft_exit_proc(char **av, int fd)
{
	if (errno == ENOENT)
		ft_putstr_fd(av[1], 2);
	ft_freetab(av);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	ft_free_proc(g_glob.head);
	if (fd != 0)
		close(fd);
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	else if (errno == ENOENT)
		exit(127);
	else
		exit(EXIT_FAILURE);
}
