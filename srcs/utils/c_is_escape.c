/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_is_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:33 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:34 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	c_is_escape(int i, char *str)
{
	int	count;

	count = 0;
	if (i == 0)
		return (NO);
	--i;
	while (i >= 0 && str[i] == '\\')
	{
		++count;
		--i;
	}
	if (count % 2)
		return (YES);
	return (NO);
}
