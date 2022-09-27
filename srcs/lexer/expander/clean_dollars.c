/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_dollars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:21 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:22 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_a_dollars_to_clean(t_list *lex)
{
	if (lex->token[0] == '$' && lex->token[1] == '\0')
		if (lex->next == NULL)
			return (NO);
	if (lex->token[0] == '$' && lex->token[1] == '\0')
		if (lex->next->kind == WD_S_QUOTE
			|| lex->next->kind == WD_D_QUOTE)
			return (YES);
	return (NO);
}

t_list	*clean_dollars(t_list *lex)
{
	t_list	*tmp;
	t_list	*new;
	char	*token;

	new = NULL;
	tmp = lex;
	while (lex)
	{
		token = NULL;
		if (is_a_dollars_to_clean(lex) == NO)
		{
			token = ft_strdup(lex->token);
			new = lst_add_back(token, lex->kind, new);
			if (token == NULL || lex == NULL)
			{
				lex = tmp;
				lst_free(new);
				return (lst_free(lex));
			}
		}
		lex = lex->next;
	}
	lex = tmp;
	lst_free(lex);
	return (new);
}
