/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:35 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:36 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_var(char *str)
{
	if (str[0] == '$')
		if (c_is_alnum(str[1]) == YES)
			return (YES);
	return (NO);
}

static	int	is_an_ambiguous_red(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (lex->kind == WD_RED && lex->next != NULL)
		{
			if (is_var(lex->next->token) == YES)
			{
				lex = tmp;
				return (YES);
			}
		}
		lex = lex->next;
	}
	lex = tmp;
	return (NO);
}

static	t_cli	*rm_cmd_from_cli(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (is_an_ambiguous_red(cli->cmd) == YES)
			cli->cmd = lst_free(cli->cmd);
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}

int	make_a_cli(t_list *cmd)
{
	t_cli	*cli;

	cli = get_cli(cmd);
	if (cli == NULL)
		return (-1);
	cli = get_redirect(cli);
	if (cli == NULL)
		return (-1);
	cli = rm_cmd_from_cli(cli);
	err_msg_ambiguous_red(cli);
	cli = rm_ambiguous_red_from_cli_red(cli);
	if (cli)
		ft_master(cli);
	g_glob.ret = 1;
	free_cli(cli);
	return (-1);
}
