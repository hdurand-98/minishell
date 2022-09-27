/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:27 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:28 by tallaire         ###   ########.fr       */
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

/*
** get the env's variable
** replace the variable's name by his assignement
*/

t_list	*expander(t_list *lex)
{
	t_list	*new;

	new = NULL;
	new = handle_token(lex, new);
	new = clean_dollars(new);
	new = do_expansion(new);
	return (new);
}
