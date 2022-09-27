/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:12 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:13 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** return the value of a variable from our env.
** If the variable does not exist, the fuction return NULL.
*/

char	*our_getenv(char *name)
{
	char	*value;
	t_list	*tmp;

	value = NULL;
	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(name, g_glob.env->name) == YES)
		{
			value = g_glob.env->value;
			g_glob.env = tmp;
			return (value);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (value);
}
