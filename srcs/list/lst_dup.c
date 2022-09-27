/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:02 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:03 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lst_dup(t_list *list)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = list;
	while (list)
	{
		new = lst_add_back(ft_strdup(list->token), list->kind, new);
		if (!new)
			return (NULL);
		list = list->next;
	}
	list = tmp;
	return (new);
}
