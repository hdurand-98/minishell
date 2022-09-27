/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:25 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:26 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_sigint(int signum)
{
	(void)signum;
	if (g_glob.aff_prompt == YES)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
	{
		ft_printf("\n");
		rl_on_new_line();
	}
	if (g_glob.ispipe == 0)
		g_glob.ret = 130;
}
