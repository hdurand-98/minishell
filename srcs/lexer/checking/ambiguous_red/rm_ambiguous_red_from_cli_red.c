/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_ambiguous_red_from_cli_red.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:41 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_var(char *str)
{
	if (str[0] == '$')
		if (c_is_alnum(str[1]) == YES)
			return (YES);
	return (NO);
}

static	t_list	*rm_ambiguous_red(t_list *red)
{
	t_list	*new;
	t_list	*tmp;
	char	*token;

	new = NULL;
	tmp = red;
	while (red)
	{
		token = NULL;
		if (is_var(red->token) == YES)
			break ;
		token = ft_strdup(red->token);
		if (token == NULL)
			return (lst_free(tmp));
		new = lst_add_back(token, red->kind, new);
		if (new == NULL)
			return (lst_free(tmp));
		red = red->next;
	}
	red = tmp;
	lst_free(red);
	return (new);
}

t_cli	*rm_ambiguous_red_from_cli_red(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (cli->red)
			cli->red = rm_ambiguous_red(cli->red);
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}
