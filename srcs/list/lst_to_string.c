/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:42 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:43 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*cat_tok(char *new, char *tok)
{
	char	*tmp;

	tmp = new;
	if (new == NULL)
	{
		new = ft_strdup(tok);
		if (new == NULL)
			return (NULL);
		return (new);
	}
	new = ft_strjoin(new, tok);
	free(tmp);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*lst_to_string(t_list *lst)
{
	t_list	*tmp_lst;
	char	*new;
	char	*tmp;

	new = NULL;
	tmp_lst = lst;
	tmp = NULL;
	while (lst)
	{
		if (lst->token)
			new = cat_tok(new, lst->token);
		lst = lst->next;
	}
	lst = tmp_lst;
	return (new);
}
