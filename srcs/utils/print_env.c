/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:16 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:17 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		ft_printf("%s=%s\n", g_glob.env->name, g_glob.env->value);
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
}
