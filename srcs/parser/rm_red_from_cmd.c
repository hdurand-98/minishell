/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_red_from_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:16 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:17 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** says if there is a redirection in the command.
*/

static	int	is_a_red(t_list *cmd)
{
	while (cmd)
	{
		if (cmd->kind == WD_RED)
			return (YES);
		cmd = cmd->next;
	}
	return (NO);
}

/*
** says if the command contains only redirections or not.
*/

static	int	is_only_red(t_list *cmd)
{
	while (cmd)
	{
		while (cmd && cmd->kind == WD_RED)
		{
			cmd = cmd->next;
			if (cmd)
				cmd = cmd->next;
		}
		if (cmd)
			return (NO);
		else
			return (YES);
	}
	return (YES);
}

static	t_list	*rm_red_continued(t_list *cmd, t_list *new)
{
	while (cmd)
	{
		while (cmd && cmd->kind == WD_RED)
		{
			cmd = cmd->next;
			while (cmd && cmd->kind == WD_SEP_TOK)
				cmd = cmd->next;
			if (cmd)
				cmd = cmd->next;
			while (cmd && cmd->kind == WD_SEP_TOK)
				cmd = cmd->next;
		}
		if (cmd && cmd->kind != WD_RED)
		{
			new = lst_add_back(ft_strdup(cmd->token), cmd->kind, new);
			if (!new)
				return (NULL);
		}
		if (cmd)
			cmd = cmd->next;
	}
	return (new);
}

/*
** remove redirection in creating a new chained list (new)
** from the command (cmd) without the redirections.
*/

static	t_list	*rm_red(t_list *cmd)
{
	t_list	*tmp_cmd;
	t_list	*new;

	tmp_cmd = cmd;
	new = NULL;
	new = rm_red_continued(cmd, new);
	cmd = tmp_cmd;
	cmd = lst_free(cmd);
	return (new);
}

/*
** remove redirection from the commands (cli->cmd)
*/

t_cli	*rm_red_from_cmd(t_cli *cli)
{
	t_cli	*tmp_cli;

	tmp_cli = cli;
	while (cli)
	{
		if (is_a_red(cli->cmd) == YES)
		{
			if (is_only_red(cli->cmd) == YES)
				cli->cmd = lst_free(cli->cmd);
			else
			{
				cli->cmd = rm_red(cli->cmd);
				if (!cli->cmd)
					return (NULL);
			}
		}
		cli = cli->next;
	}
	cli = tmp_cli;
	return (cli);
}
