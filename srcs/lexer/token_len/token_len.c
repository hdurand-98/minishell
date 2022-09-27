/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:40 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:41 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
** Calcul the len of a simple token.
*/

static	size_t	word_len(size_t i, char *str)
{
	while (str[i] && ((c_is_str(str[i], C_GRAM) == NO)))
		++i;
	return (i);
}

/*
** Calcul the len of a token inside quotes ("" ; '').
*/

static	size_t	quote_len(size_t i, char *str)
{
	int	y;

	y = i;
	while (str[i] && is_quote(i, str) == YES)
		++i;
	return (i);
}

/*
** Calcul the len of a grammatical token ('|' '<' '>').
*/

static	size_t	gram_len(size_t i, char *str, char gram)
{
	while (str[i] && str[i] == gram)
		++i;
	return (i);
}

/*
** Calcul the len of a separator token (' ').
*/

static	size_t	sep_len(int i, char *str)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		++i;
	return (i);
}

/*
** Calcul the len of a token
** Tokens are split by ';' '|' '>' '<' ' ' '"' '''.
** Separator (' ') are considerates as token in this beautiful shell.
*/

size_t	token_len(size_t y, char *str)
{
	size_t	i;

	i = y;
	if (str[i] == '\'' || str[i] == '\"')
		i = quote_len(i, str);
	else if (c_is_str(str[i], C_SEP_CMD) == YES
		|| c_is_str(str[i], C_RED) == YES)
		i = gram_len(i, str, str[i]);
	else if (str[i] == ' ' || str[i] == '\t')
		i = sep_len(i, str);
	else
		i = word_len(i, str);
	i -= y;
	if (c_is_str(str[y], C_QUOTE) == YES)
		i = len_first_quote(str + y, i);
	return (i);
}
