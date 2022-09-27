/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   successive_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:11 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:12 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if a red is the last token or not of the command.
*/

static	int	is_ending_by_red(t_list *lex)
{
	if (lex && lex->kind == WD_RED && lex->next == NULL)
	{
		print_stx_err("newline", (-1));
		return (YES);
	}
	return (NO);
}

/*
** check if a command separator ('|',';') is just after a redirection.
*/

static	int	is_sep_cmd_after_red(t_list *lex)
{
	if (lex && lex->kind == WD_RED && lex->next->kind == WD_SEP_CMD)
	{
		print_stx_err(lex->next->token, lex->next->kind);
		return (YES);
	}
	return (NO);
}

/*
** check if a redirection ('<', '<<', '>', '>>') is just after a redirection.
*/

static	int	is_red_after_red(t_list *lex)
{
	if (lex && lex->kind == WD_RED && lex->next->kind == WD_RED)
	{
		g_glob.ret = 2;
		print_stx_err(lex->next->token, lex->next->kind);
		return (YES);
	}
	return (NO);
}

/*
** check if there is not two successive token command separator ('|', ';')
** or redirection ('>', '>>', '<', '<<').
*/

int	successive_token(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (is_ending_by_red(lex) == YES)
			return (-1);
		if (is_sep_cmd_after_red(lex) == YES)
			return (-1);
		if (is_red_after_red(lex) == YES)
			return (-1);
		lex = lex->next;
	}
	lex = tmp;
	return (0);
}
