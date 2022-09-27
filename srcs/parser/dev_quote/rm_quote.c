/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:54 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:55 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
** Says if the token has quotes interlocked ("''" | '""').
*/

static	int	are_quote_interlocked(char *str)
{
	int	i;
	int	simple;
	int	twice;

	i = 0;
	simple = 0;
	twice = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
			++simple;
		else if (str[i] == '\"')
			++twice;
		++i;
	}
	if (simple > 0 && twice > 0)
		return (YES);
	else
		return (NO);
}

/*
** delete the interlocked quotes none escaped of the token (str).
*/

static	char	*rm_interlocked_quote(char *str)
{
	char	*new;
	char	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quote = *str;
	new = malloc(ft_strlen(str) - 2 + 1);
	if (!new)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] != quote)
		{
			new[j] = str[i];
			++j;
		}
		++i;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

/*
** delete the quotes none escaped of the token (str).
*/

char	*rm_quote(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (are_quote_interlocked(str) == YES)
		return (rm_interlocked_quote(str));
	new = malloc(ft_strlen(str) - 2 + 1);
	if (!new)
		return (NULL);
	while (str[i] && (c_is_str(str[i], C_QUOTE) == NO))
	{
		new[j] = str[i];
		++j;
		++i;
	}
	new[j] = '\0';
	free(str);
	return (new);
}
