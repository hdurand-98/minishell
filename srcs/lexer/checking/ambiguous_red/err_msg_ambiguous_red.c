/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_ambiguous_red.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:24 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:25 by tallaire         ###   ########.fr       */
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
		if (is_var(lex->token) == YES)
		{
			lex = tmp;
			return (YES);
		}
		lex = lex->next;
	}
	lex = tmp;
	return (NO);
}

static	void	print_msg(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (is_var(cmd->token) == YES)
		{
			ft_printf("minishell: %s :", cmd->token);
			ft_printf(" ambiguous redirection\n");
			break ;
		}
		cmd = cmd->next;
	}
	cmd = tmp;
}

void	err_msg_ambiguous_red(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (is_an_ambiguous_red(cli->red) == YES)
		{
			print_msg(cli->red);
			break ;
		}
		cli = cli->next;
	}
}
