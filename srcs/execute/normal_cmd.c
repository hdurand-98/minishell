/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:46 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:40:47 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_end_of_pipe_cmd(int *piped, t_cli **cli, int **fdptab, int *i)
{
	int	fdp;

	fdp = fork();
	if (fdp == 0)
	{
		signal(SIGQUIT, do_sigquit);
		ft_duped(piped, 0);
		free((*fdptab));
		ft_child_proc((*cli));
	}
	else if (fdp > 0)
	{
		signal(SIGQUIT, do_sigquit);
		(*fdptab)[*i] = fdp;
		*i = *i + 1;
		close(*piped);
	}
	else
		ft_printf("%s\n", strerror(errno));
}

void	ft_execute_norm_cmd(t_cli *cli)
{
	int	fdp;
	int	status;

	fdp = fork();
	if (fdp == 0)
	{
		signal(SIGQUIT, do_sigquit);
		ft_execute_prog(cli);
	}
	else if (fdp > 0)
	{
		signal(SIGQUIT, do_sigquit);
		wait(&status);
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
	else
		ft_printf("%s\n", strerror(errno));
}

void	ft_no_pipe_cmd(t_cli *cli)
{
	int	std_out;
	int	std_in;
	int	ret;

	std_out = dup(1);
	std_in = dup(0);
	ret = ft_redir(cli->red);
	if (ret != 0 && cli->cmd != NULL)
	{
		ret = is_a_built_in(cli);
		if (ret < 0)
			g_glob.ret = ret * -1;
		else if (ret == 0)
			ft_execute_norm_cmd(cli);
	}
	else if (ret == 0 && g_glob.ret != 130)
	{
		dup2(std_out, 1);
		dup2(std_in, 0);
		ft_printf("%s\n", strerror(errno));
	}
	dup2(std_out, 1);
	dup2(std_in, 0);
}

void	ft_normal_cmd(int *piped, t_cli **cli, int **fdptab, int *i)
{
	if (*piped > 0)
		ft_end_of_pipe_cmd(piped, cli, fdptab, i);
	else
		ft_no_pipe_cmd((*cli));
	(*cli) = (*cli)->next;
}
