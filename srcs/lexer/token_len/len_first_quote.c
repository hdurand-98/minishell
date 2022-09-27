/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_first_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:37 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
** give the len of the first token between double quotes ("")
** when you have several token between double quote
** not split by separators (' ').
*/

int	len_first_quote(char *str, int size)
{
	int		nb_quote;
	char	quote;
	int		i;

	quote = *str;
	nb_quote = 0;
	i = 0;
	while (i < size)
	{
		if (nb_quote == 2)
			return (i);
		if (str[i] == quote && c_is_escape(i, str) == NO)
			++nb_quote;
		++i;
	}
	return (size);
}
