/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:10 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:40:11 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_duped(int *piped, int piped_fd)
{
	dup2(*piped, piped_fd);
	close(*piped);
	*piped = -1;
}

void	ft_child_proc(t_cli *cli)
{
	int	ret;

	if (ft_redir(cli->red) == 0)
		ft_exit_proc(NULL, 0);
	if (cli->cmd == NULL)
	{
		ft_free_proc(g_glob.head);
		exit(EXIT_SUCCESS);
	}
	ret = is_a_built_in(cli);
	if (ret == 1)
	{
		ft_free_proc(g_glob.head);
		exit(EXIT_SUCCESS);
	}
	else if (ret < 0)
	{
		ft_free_proc(g_glob.head);
		exit(ret * -1);
	}
	else
		ft_execute_prog(cli);
}

void	ft_start_of_pipe(int *pipefds, int *piped, t_cli **cli, int **fdptab)
{
	close(pipefds[0]);
	dup2(pipefds[1], 1);
	close(pipefds[1]);
	if (*piped > 0)
		ft_duped(piped, 0);
	free((*fdptab));
	ft_child_proc((*cli));
}

void	ft_pipe_failed(t_cli **cli)
{
	ft_printf("%s\n", strerror(errno));
	(*cli) = NULL;
	return ;
}

void	ft_piped_cmd(int *piped, t_cli **cli, int **fdptab, int *i)
{
	int	pipefds[2];
	int	fdp;

	if (pipe(pipefds) == -1)
		return (ft_pipe_failed(cli));
	fdp = fork();
	if (fdp == 0)
	{
		signal(SIGQUIT, do_sigquit);
		ft_start_of_pipe(pipefds, piped, cli, fdptab);
	}
	else if (fdp > 0)
	{
		signal(SIGQUIT, do_sigquit);
		(*fdptab)[(*i)++] = fdp;
		if (*piped > 0)
			close(*piped);
		close(pipefds[1]);
		*piped = pipefds[0];
		(*cli) = (*cli)->next;
		return ;
	}
	else
		ft_printf("%s\n", strerror(errno));
	(*cli) = NULL;
}
