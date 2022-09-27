/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gram_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:49 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:50 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_red_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	if (str[0] == '<' && i > 2)
	{
		ft_printf("minishell: unexpected syntax's error");
		ft_printf(" \" << \"\n");
		return (NO);
	}
	else if (str[0] == '>' && i > 2)
	{
		ft_printf("minishell: unexpected syntax's error");
		ft_printf(" \" >> \"\n");
		return (NO);
	}
	return (YES);
}

static	int	is_gram_tok_valid(char *str, int kind)
{
	int	i;

	i = 0;
	if (kind == WD_SEP_CMD)
	{
		while (str[i])
			++i;
		if (i > 1)
		{
			ft_printf("minishell: unexpected syntax's error");
			ft_printf(" \" %c \"\n", str[0]);
			return (NO);
		}
	}
	else if (kind == WD_RED)
		if (is_red_valid(str))
			return (NO);
	return (YES);
}

int	check_gram_char(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (lex->kind == WD_SEP_CMD || lex->kind == WD_RED)
		{
			if (is_gram_tok_valid(lex->token, lex->kind))
			{
				lex = tmp;
				return (-1);
			}
		}
		lex = lex->next;
	}
	lex = tmp;
	return (0);
}
