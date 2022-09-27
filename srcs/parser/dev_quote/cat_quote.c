/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:48 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:49 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
** Says if the next token (cmd->next->token) has to be concatanate
** with the current token (cmd->token).
*/

static	int	is_a_cat(t_list *cmd)
{
	if (cmd == NULL || cmd->next == NULL)
		return (NO);
	if (cmd->kind != WD_SEP_TOK && cmd->next->kind != WD_SEP_TOK)
		return (YES);
	return (NO);
}

/*
** Says if there is token to concatenate in the command (cmd).
*/

static	int	is_need_to_cat(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (is_a_cat(cmd) == YES)
			return (YES);
		cmd = cmd->next;
	}
	cmd = tmp;
	return (NO);
}

/*
** concatenate the current token (cmd->token)
** with the next one (cmd->next->token).
*/

t_list	*cat_token(t_list *cmd)
{
	char	*new_token;

	new_token = ft_strjoin(cmd->token, cmd->next->token);
	if (!new_token)
		return (NULL);
	free(cmd->token);
	cmd->token = new_token;
	cmd = lst_rm_next(cmd);
	return (cmd);
}

/*
** Concatanate tokens (cmd->token) wich are not separate by separator (' ').
*/

t_list	*cat_quote(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	if (is_need_to_cat(cmd) == NO)
		return (cmd);
	while (cmd)
	{
		if (is_a_cat(cmd) == YES)
		{
			cmd = cat_token(cmd);
			if (!cmd)
				return (NULL);
		}
		else
			cmd = cmd->next;
	}
	cmd = tmp;
	return (cmd);
}
