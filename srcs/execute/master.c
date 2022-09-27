/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:39:42 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:39:44 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_fdptab(t_cli *cli)
{
	int	i;
	int	*fdptab;

	i = 1;
	while (cli != NULL && cli->sep == 1)
	{
		i++;
		cli = cli->next;
	}
	if (i == 1)
		return (NULL);
	else
		fdptab = malloc(sizeof(int) * (i + 1));
	return (fdptab);
}

void	ft_print_crdmp(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (Core dumped)\n", 2);
}

void	ft_wait_piped_cmd(int **fdptab, int i)
{
	int	status;
	int	fdp;
	int	tempfdp;

	fdp = 0;
	(*fdptab)[i] = -1;
	i = -1;
	while ((*fdptab)[++i] != -1)
	{
		tempfdp = wait(&status);
		if (tempfdp > fdp)
		{
			fdp = tempfdp;
			if (WIFEXITED(status) == 1)
				g_glob.ret = status / 256;
			else if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGQUIT)
					g_glob.ret = 131;
				else if (WTERMSIG(status) == SIGINT)
					g_glob.ret = 130;
			}
		}
	}
	free((*fdptab));
}

int	ft_master(t_cli *cli)
{
	int	i;
	int	piped;
	int	*fdptab;

	piped = -1;
	i = 0;
	g_glob.ispipe = 0;
	if (cli == NULL)
		return (0);
	else
		fdptab = ft_fdptab(cli);
	while (cli != NULL)
	{
		g_glob.ret = 0;
		if (cli->sep == 0)
			ft_normal_cmd(&piped, &cli, &fdptab, &i);
		else if (cli->sep == 1)
		{
			g_glob.ispipe = 1;
			ft_piped_cmd(&piped, &cli, &fdptab, &i);
		}
	}
	if (fdptab != NULL)
		ft_wait_piped_cmd(&fdptab, i);
	return (0);
}
