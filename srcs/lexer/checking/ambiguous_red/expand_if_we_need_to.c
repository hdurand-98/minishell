/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_if_we_need_to.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:28 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:29 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_list	*add_back_token(char *str, int kind, t_list *lex)
{
	char	*token;

	token = NULL;
	if (kind == WD_S_QUOTE || (kind != WD_S_QUOTE && c_is_str('$', str) != YES))
	{
		token = ft_strdup(str);
		if (token == NULL)
			return (NULL);
		return (lex = lst_add_back(token, kind, lex));
	}
	lex = token_expander(str, kind, lex);
	return (lex);
}

static	t_list	*handle_token(t_list *lex, t_list *new)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		new = add_back_token(lex->token, lex->kind, new);
		if (new == NULL)
		{
			lex = tmp;
			return (lst_free(lex));
		}
		lex = lex->next;
	}
	lex = tmp;
	lst_free(lex);
	return (new);
}

t_list	*expand_if_we_need_to(t_list *lex)
{
	t_list	*new;

	new = NULL;
	new = handle_token(lex, new);
	new = expander_ambiguous(new);
	return (new);
}
