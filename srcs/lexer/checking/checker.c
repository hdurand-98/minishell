/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:54 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:55 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if the first token is not a command separator ('|', ';')
*/

static	int	is_first_tok_okey(char *str, int kind)
{
	if (kind == WD_SEP_CMD)
	{
		g_glob.ret = 2;
		print_stx_err(str, kind);
		return (NO);
	}
	else
		return (YES);
}

int	checker(t_list *lex)
{
	t_list	*cmd;

	cmd = rm_sep_tok(lex);
	if (!cmd)
		return (-1);
	if (is_first_tok_okey(lex->token, lex->kind) == NO
		|| successive_token(cmd)
		|| check_gram_char(cmd))
	{
		g_glob.ret = 2;
		lst_free(cmd);
		return (-1);
	}
	if (check_ambiguous_red(cmd))
	{
		lst_free(cmd);
		return (-1);
	}
	lst_free(cmd);
	return (0);
}
