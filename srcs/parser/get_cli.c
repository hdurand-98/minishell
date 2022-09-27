/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:01 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lst_dup_cli(t_list *list, int *stop)
{
	t_list	*new;
	t_list	*tmp;

	*stop = NO;
	new = NULL;
	tmp = list;
	while (list)
	{
		new = lst_add_back(ft_strdup(list->token), list->kind, new);
		if (!new)
		{
			*stop = YES;
			return (NULL);
		}
		list = list->next;
	}
	list = tmp;
	return (new);
}

/*
** split the command line in simple commands
** in function of the command separators (';' '|').
*/

t_cli	*get_cli(t_list *lex)
{
	t_cli	*cli;
	t_list	*cmd;
	t_list	*dup;

	cli = NULL;
	cmd = NULL;
	dup = NULL;
	cli = get_cli_continued(lex, cli, cmd, dup);
	return (cli);
}
