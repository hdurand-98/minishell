/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_cli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:14 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:15 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	print_cmd(t_list *cmd, int kind)
{
	t_list	*tmp;

	tmp = cmd;
	if (kind == CLI_CMD)
		ft_printf("%sCMD >%s ", GREEN, NC);
	else if (kind == CLI_VAR)
		ft_printf("%sVAR >%s ", GREEN, NC);
	else
		ft_printf("%sCMD >%s ", GREEN, NC);
	while (cmd)
	{
		ft_printf("%s ", cmd->token);
		cmd = cmd->next;
	}
	ft_printf("\n");
	cmd = tmp;
}

static	void	print_redirection(int kind)
{
	if (kind == R_STDIN)
		ft_printf("< ");
	else if (kind == R_STDOUT)
		ft_printf("> ");
	else if (kind == R_STDOUT_APP)
		ft_printf(">> ");
	else
		ft_printf("<< ");
}

static	void	print_red(t_list *red)
{
	t_list	*tmp;

	tmp = red;
	ft_printf("%sRED >%s ", YELLOW, NC);
	while (red)
	{
		print_redirection(red->kind);
		ft_printf("%s ", red->token);
		red = red->next;
	}
	ft_printf("\n");
	red = tmp;
}

void	lst_print_cli(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		print_cmd(cli->cmd, cli->kind);
		print_red(cli->red);
		ft_printf("SEP | %d\n", cli->sep);
		cli = cli->next;
	}
	cli = tmp;
}
