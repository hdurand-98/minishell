/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:07 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_to_next_quote(char *str, int i, char quote)
{
	++i;
	while (str[i] && (str[i] != quote || c_is_escape(i, str) == YES))
		++i;
	return (i);
}
