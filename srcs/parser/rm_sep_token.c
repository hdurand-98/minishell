/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_sep_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:19 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** Delete the first and last token (cmd->token) of the command (cmd)
** if their kind are separator token (' ').
*/

static	t_list	*rm_sep_back_and_front(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	if (cmd->kind == WD_SEP_TOK)
		cmd = lst_rm_front(cmd);
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->kind == WD_SEP_TOK)
		cmd = lst_rm_back(cmd);
	return (cmd);
}

/*
** delete separator token (cmd->token) in the command (cmd).
*/

static	t_list	*change_cmd(t_list *cmd)
{
	t_list	*tmp;

	cmd = rm_sep_back_and_front(cmd);
	tmp = cmd;
	while (cmd)
	{
		if (cmd->next && cmd->next->kind == WD_SEP_TOK)
			cmd = lst_rm_next(cmd);
		else if (cmd)
			cmd = cmd->next;
	}
	cmd = tmp;
	return (cmd);
}

/*
** delete separator token (cli->cmd->token) in the command line (cli).
*/

t_cli	*rm_sep_token(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (cli->cmd)
		{
			cli->cmd = change_cmd(cli->cmd);
			if (!cli->cmd)
				return (NULL);
		}
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}
