/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:36 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_list	*lst_first_link_var(char *name, char *value, int kind)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->value = value;
	new->kind = kind;
	new->next = NULL;
	return (new);
}

t_list	*env_add_back(char *name, char *value, int kind, t_list *arg)
{
	t_list	*tmp;
	t_list	*new;

	tmp = arg;
	if (arg == NULL)
		return (lst_first_link_var(name, value, kind));
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->value = value;
	new->kind = kind;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (arg);
}
