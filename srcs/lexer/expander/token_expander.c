/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:29 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:30 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return the size of a new token wich is between double quotes.
*/

static	size_t	len_tok_var_double_quote(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] != '$')
	{
		while (str[i] && str[i] != '$' && str[i] != '\"')
			++i;
	}
	else
	{
		++i;
		if (str[i] == '?')
			return (i + 1);
		while (str[i] && str[i] != '\"' && str[i] != '$'
			&& (c_is_alnum(str[i]) == YES || str[i] == '_'))
			++i;
	}
	return (i);
}

/*
** dup the token and add "\"" at the start and end of the token.
*/

static	char	*dup_tok_double_quote(char *str, size_t size)
{
	char	*tmp;
	char	*new;
	char	*token;

	token = ft_strldup(str, size);
	new = NULL;
	tmp = NULL;
	new = ft_strdup("\"");
	if (new == NULL)
		return (NULL);
	tmp = new;
	if (new)
		new = ft_strjoin(new, token);
	free(token);
	free(tmp);
	tmp = new;
	if (new)
		new = ft_strjoin(new, "\"");
	free(tmp);
	return (new);
}

static	t_list	*token_expander_double_quote(char *str, t_list *lex)
{
	size_t	size;
	char	*token;
	size_t	i;

	i = 0;
	size = 0;
	++i;
	while (str[i] && str[i] != '\"')
	{
		size = len_tok_var_double_quote(str + i);
		token = dup_tok_double_quote(str + i, size);
		if (token == NULL)
			return (NULL);
		lex = lst_add_back(token, WD_D_QUOTE, lex);
		token = NULL;
		if (lex == NULL)
			return (NULL);
		i += size;
	}
	return (lex);
}

/*
** return the size of a new token wich is not between double quotes.
*/

static	size_t	len_tok_var(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] != '$')
	{
		while (str[i] && str[i] != '$')
			++i;
	}
	else
	{
		++i;
		if (str[i] == '?')
			return (i + 1);
		while (str[i] && str[i] != '$'
			&& (c_is_alnum(str[i]) == YES || str[i] == '_'))
			++i;
	}
	return (i);
}

t_list	*token_expander(char *str, int kind, t_list *lex)
{
	size_t	size;
	char	*token;
	size_t	i;

	i = 0;
	size = 0;
	if (kind == WD_D_QUOTE)
		return (token_expander_double_quote(str, lex));
	while (str[i])
	{
		size = len_tok_var(str + i);
		token = ft_strldup(str + i, size);
		if (token == NULL)
			return (NULL);
		lex = lst_add_back(token, kind, lex);
		token = NULL;
		if (lex == NULL)
			return (NULL);
		i += size;
	}
	return (lex);
}
