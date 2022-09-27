/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:51 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:52 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
** return a modifyed token (str).
*/

static	char	*change_token(char *str)
{
	str = rm_quote(str);
	if (!str)
		return (NULL);
	return (str);
}

/*
** return a modifyed command (cmd).
*/

static	t_list	*change_cmd(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (cmd->kind == WD_S_QUOTE || cmd->kind == WD_D_QUOTE)
		{
			cmd->token = change_token(cmd->token);
			if (!cmd->token)
				return (NULL);
		}
		cmd = cmd->next;
	}
	cmd = tmp;
	return (cmd);
}

/*
** develop the quotes in the all the token of
** the command line.
*/

t_cli	*dev_quote(t_cli *cli)
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
			cli->cmd = cat_quote(cli->cmd);
			if (!cli->cmd)
				return (NULL);
		}
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}
