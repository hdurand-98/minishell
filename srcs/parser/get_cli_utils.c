/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cli_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:57 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:58 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_cli	*first_cli(t_list *cmd, t_list *red, int sep, t_cli *cli)
{
	cli = (t_cli *)malloc(sizeof(t_cli));
	if (!cli)
		return (NULL);
	cli->cmd = cmd;
	cli->red = red;
	cli->sep = sep;
	cli->next = NULL;
	return (cli);
}

static	t_cli	*cli_add_back(t_list *cmd, t_list *red, int sep, t_cli *cli)
{
	t_cli	*new;
	t_cli	*tmp;

	tmp = cli;
	if (cli == NULL)
		return (first_cli(cmd, red, sep, cli));
	new = (t_cli *)malloc(sizeof(t_cli));
	if (!new)
	{
		lst_free(red);
		return ((t_cli *)lst_free(cmd));
	}
	new->cmd = cmd;
	new->red = red;
	new->sep = sep;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (cli);
}

static	t_list	*get_cmd(t_list *cmd, t_list *lex, int *stop)
{
	*stop = NO;
	while (lex && lex->kind == WD_SEP_TOK)
		lex = lex->next;
	while (lex && lex->kind != WD_SEP_CMD)
	{
		cmd = lst_add_back(ft_strdup(lex->token),
				lex->kind, cmd);
		if (!cmd)
		{
			*stop = YES;
			return (NULL);
		}
		lex = lex->next;
	}
	return (cmd);
}

static	t_list	*move_lex(t_list *lex)
{
	while (lex && lex->kind != WD_SEP_CMD)
		lex = lex->next;
	return (lex);
}

t_cli	*get_cli_continued(t_list *lex, t_cli *cli, t_list *cmd, t_list *dup)
{
	int	sep;
	int	stop;

	while (lex)
	{
		sep = 0;
		if (lex != NULL)
			cmd = get_cmd(cmd, lex, &stop);
		if (!cmd && stop == YES)
			return (NULL);
		lex = move_lex(lex);
		dup = lst_dup_cli(cmd, &stop);
		if (!dup && stop == YES)
			return (NULL);
		if (lex && lex->token[0] == '|')
			sep = 1;
		cli = cli_add_back(dup, NULL, sep, cli);
		if (!cli)
			return (NULL);
		sep = 0;
		cmd = lst_free(cmd);
		if (lex)
			lex = lex->next;
	}
	return (cli);
}
