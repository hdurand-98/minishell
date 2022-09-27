/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:51 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:52 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minishell.h"

/*
** Says if the token is a variable affectation.
** check if the variable affection used the right characters :
** - Only alpha numeric char (0-9 ; a-z ; A-Z) and underscore ('_')
** for the name.
*/

static	int	is_aff_var(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && (c_is_alnum(str[i]) == YES || str[i] == '_'))
		++i;
	if (str[i] != '=' || i == 0)
		return (NO);
	else
		return (YES);
}

/*
** return the kind of a token.
**
** C_SEP_TOK	' ' '\t'
** C_SEP_CMD	'|'
** C_RED	'>' '<'
** C_S_QUOTE	'\''
** C_D_QUOTE	'\"'
** WD_AFF_VAR	"var_name=value"
*/

static	int	kind(char *str)
{
	if (c_is_str(*str, C_SEP_CMD) == YES)
		return (WD_SEP_CMD);
	else if (c_is_str(*str, C_SEP_TOK) == YES)
		return (WD_SEP_TOK);
	else if (c_is_str(*str, C_S_QUOTE) == YES)
		return (WD_S_QUOTE);
	else if (c_is_str(*str, C_D_QUOTE) == YES)
		return (WD_D_QUOTE);
	else if (c_is_str(*str, C_RED) == YES)
		return (WD_RED);
	else if (is_aff_var(str) == YES)
		return (WD_VAR_AFF);
	else
		return (WD_TOK);
}

/*
** put token in a chained list (lex).
*/

static	t_list	*lst_token(t_list *lex, char *str)
{
	size_t	i;
	size_t	size;
	char	*token;

	i = 0;
	size = 0;
	token = NULL;
	while (str[i])
	{
		size = token_len(i, str);
		token = ft_strldup(str + i, size);
		if (!token)
			return (NULL);
		lex = lst_add_back(token, kind(token), lex);
		if (!lex)
			return (NULL);
		i += size;
	}
	return (lex);
}

t_list	*lexer(char *line, t_list *lex)
{
	lex = lst_token(lex, line);
	if (!lex)
		return (NULL);
	lex = add_sep_tok_for_red(lex);
	if (lex == NULL)
		return (lst_free(lex));
	if (is_quote_even(lex) == NO)
		return (NULL);
	if (checker(lex))
		return (lst_free(lex));
	lex = expander(lex);
	if (lex == NULL)
		return (NULL);
	return (lex);
}
