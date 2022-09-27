/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:23 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:24 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	where_is_c(char c, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
