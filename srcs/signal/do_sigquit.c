/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sigquit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:28 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:29 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_sigquit(int signum)
{
	ft_printf("Quit (core dumped)\n");
	signal(SIGQUIT, SIG_DFL);
	(void)signum;
}

void	do_sigign(int signum)
{
	ft_putstr_fd("\b\b  \b\b", 0);
	(void)signum;
}
