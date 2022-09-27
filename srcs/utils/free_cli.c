/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:39 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:40 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cli	*free_cli(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		tmp = cli;
		cli->cmd = lst_free(cli->cmd);
		cli->red = lst_free(cli->red);
		cli = cli->next;
		free(tmp);
	}
	return (NULL);
}
