/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:30 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:31 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** For a simple chained list
** delete the next link of the list.
*/

t_list	*lst_rm_next(t_list *lst)
{
	t_list	*next;

	next = NULL;
	if (lst == NULL || lst->next == NULL)
		return (lst);
	next = lst->next->next;
	free(lst->next->token);
	free(lst->next);
	lst->next = next;
	return (lst);
}
