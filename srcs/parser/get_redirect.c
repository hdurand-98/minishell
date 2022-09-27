/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:04 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/30 19:49:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** tel wich kind of redirection is the token.
*/

static	int	wich_redirect(char *str)
{
	if (str[0] == '>' && str[1] == '\0')
		return (R_STDOUT);
	else if (str[0] == '<' && str[1] == '\0')
		return (R_STDIN);
	else if (str[0] == '>' && str[1] == '>' && str[2] == '\0')
		return (R_STDOUT_APP);
	else
		return (R_HEREDOC);
}

/*
** say if redirection are present or not in the command.
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
** get redirection from one comand.
*/

static	t_list	*get_red(t_list *cmd)
{
	t_list	*red;
	int		red_code;

	red = NULL;
	red_code = 0;
	while (cmd)
	{
		if (cmd->kind == WD_RED)
		{
			red_code = wich_redirect(cmd->token);
			cmd = cmd->next;
			while (cmd && cmd->kind == WD_SEP_TOK)
				cmd = cmd->next;
			red = lst_add_back(ft_strdup(cmd->token),
					red_code, red);
			if (!red)
				return (NULL);
		}
		if (cmd)
			cmd = cmd->next;
	}
	return (red);
}

/*
** take redirection from cli->cmd
** and put them in another chained list (cli->red).
*/

t_cli	*get_redirect(t_cli *cli)
{
	t_cli	*tmp_cli;

	tmp_cli = cli;
	while (cli)
	{
		if (cli->cmd && cli->cmd->kind != WD_SEP_CMD)
		{
			if (is_a_red(cli->cmd) == YES)
			{
				cli->red = get_red(cli->cmd);
				if (!cli->red)
					return (NULL);
			}
		}
		cli = cli->next;
	}
	cli = tmp_cli;
	return (cli);
}
