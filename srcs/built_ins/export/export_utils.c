/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:38:30 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:38:31 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*join_export(char *name, char *value, int kind)
{
	char	*join;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 11;
	j = 0;
	size = 11 + ft_strlen(name) + ft_strlen(value) + 1;
	if (kind == 0)
		size += 3;
	join = malloc(sizeof(char *) * size);
	if (join == NULL)
		return (NULL);
	ft_strcpy(join, "declare -x ");
	ft_strcpy(join + 11, name);
	if (kind == 0)
	{
		ft_strcpy(join + 11 + ft_strlen(name), "=\"");
		ft_strcpy(join + 11 + ft_strlen(name) + 2, value);
		ft_strcpy(join + 11 + ft_strlen(name) + 2 + ft_strlen(value),
			"\"");
	}
	return (join);
}

t_list	*join_env_in_tab(t_list *env)
{
	char	*join;
	t_list	*cpy;
	t_list	*tmp;

	tmp = env;
	join = NULL;
	cpy = NULL;
	while (env)
	{
		join = join_export(env->name, env->value, env->kind);
		if (join == NULL)
			return (NULL);
		cpy = lst_add_back(join, 0, cpy);
		if (cpy == NULL)
		{
			free(join);
			return (lst_free(cpy));
		}
		env = env->next;
	}
	env = tmp;
	return (cpy);
}
