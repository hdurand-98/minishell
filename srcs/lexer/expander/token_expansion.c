/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:32 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	size_t	len_token(char *str, int *kind)
{
	size_t	i;

	i = 0;
	if (str[0] == ' ')
	{
		while (str[i] && str[i] == ' ')
			++i;
		*kind = WD_SEP_TOK;
	}
	else
	{
		while (str[i] && str[i] != ' ')
			++i;
		*kind = WD_TOK;
	}
	return (i);
}

static	t_list	*parse_value(char *value, t_list *lex)
{
	int		kind;
	size_t	i;
	size_t	size;
	char	*token;

	i = 0;
	size = 0;
	kind = WD_TOK;
	while (value[i])
	{
		token = NULL;
		size = len_token(value + i, &kind);
		token = ft_strldup(value + i, size);
		if (token == NULL)
			return (NULL);
		lex = lst_add_back(token, kind, lex);
		if (lex == NULL)
		{
			free(token);
			return (NULL);
		}
		i += size;
	}
	return (lex);
}

t_list	*token_expansion(char *str, t_list *lex)
{
	char	*value;

	value = our_getenv(str);
	if (value == NULL)
		return (NULL);
	lex = parse_value(value, lex);
	return (lex);
}
