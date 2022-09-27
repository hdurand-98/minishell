/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_even.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:44 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:45 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
** Says if the simple quotes inside a token are even or not.
** if there is no quotes inside the token, the function answer YES.
*/

static	int	is_simple_quote_even(char *str, int kind)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	if (kind != WD_S_QUOTE)
		return (YES);
	while (str && str[i])
	{
		if (c_is_str(str[i], C_S_QUOTE) == YES)
			++quote;
		++i;
	}
	if (quote % 2 != 0)
		return (NO);
	else
		return (YES);
}

/*
** Says if the double quotes inside a token are even or not.
** if there is no quotes inside the token, the function answer YES.
*/

static	int	is_double_quote_even(char *str, int kind)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	if (kind != WD_D_QUOTE)
		return (YES);
	while (str && str[i])
	{
		if (c_is_str(str[i], C_D_QUOTE) == YES)
			++quote;
		++i;
	}
	if (quote % 2 != 0)
		return (NO);
	else
		return (YES);
}

/*
** Says if the quote insid the lexer are even or not.
** if there is no quotes inside the token, the function answer YES.
*/

int	is_quote_even(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (is_simple_quote_even(lex->token, lex->kind) == NO)
		{
			ft_printf("minishell : ");
			ft_printf("Simple quotes are not even\n");
			return (NO);
		}
		if (is_double_quote_even(lex->token, lex->kind) == NO)
		{
			ft_printf("minishell : ");
			ft_printf("Simple quotes are not even\n");
			return (NO);
		}
		lex = lex->next;
	}
	lex = tmp;
	return (YES);
}
