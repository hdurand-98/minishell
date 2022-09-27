/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:27 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lst_rm_front(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return (NULL);
	tmp = list->next;
	if (list->token)
		free(list->token);
	free(list);
	return (tmp);
}
