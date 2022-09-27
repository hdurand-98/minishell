/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:12:12 by user42            #+#    #+#             */
/*   Updated: 2021/09/16 10:39:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_list *cmd)
{
	t_list	*tmp;

	(void)cmd;
	if (g_glob.env == NULL)
	{
		g_glob.ret = 1;
		return (1);
	}
	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (g_glob.env->kind == YES)
		{
			ft_printf("%s", g_glob.env->name);
			ft_printf("=");
			ft_printf("%s", g_glob.env->value);
			ft_printf("\n");
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	g_glob.ret = 0;
	return (1);
}
