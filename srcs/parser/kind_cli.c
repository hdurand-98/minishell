/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kind_cli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:07 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	int	is_aff_var(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (cmd->kind != WD_VAR_AFF)
			return (NO);
		cmd = cmd->next;
	}
	cmd = tmp;
	return (YES);
}

t_cli	*kind_cli(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (cli->cmd && cli->cmd->kind == WD_SEP_TOK)
			cli->kind = CLI_SEP;
		else if (cli->cmd && is_aff_var(cli->cmd) == YES)
			cli->kind = CLI_VAR;
		else if (cli->cmd)
			cli->kind = CLI_CMD;
		else
			cli->kind = CLI_NO_CMD;
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}
