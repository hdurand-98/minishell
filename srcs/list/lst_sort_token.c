/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:38 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	swap_tok(t_list *pile)
{
	char	*tmp_tok;

	if (pile == NULL || pile->next == NULL)
		return ;
	tmp_tok = pile->token;
	pile->token = pile->next->token;
	pile->next->token = tmp_tok;
}

static	int	is_lst_sort(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list->next)
	{
		if (ft_strcmp(list->token, list->next->token) > 0)
		{
			list = tmp;
			return (NO);
		}
		list = list->next;
	}
	list = tmp;
	return (YES);
}

void	lst_sort_token(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (is_lst_sort(list) == NO)
	{
		while (list->next)
		{
			if (ft_strcmp(list->token, list->next->token) > 0)
				swap_tok(list);
			list = list->next;
		}
		list = tmp;
	}
}
