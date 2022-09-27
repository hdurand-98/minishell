/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:10 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** add a link at the back of the list
** and set env->name of the new link
*/

static	t_list	*add_name(char *name, t_list *env)
{
	t_list	*new;
	t_list	*tmp;

	tmp = env;
	if (env == NULL)
	{
		env = (t_list *)malloc(sizeof(t_list));
		if (!env)
			return (NULL);
		env->name = name;
		env->next = NULL;
		return (env);
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(name);
		return (NULL);
	}
	new->name = name;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (env);
}

/*
** Set env->value of the last list's link.
*/

static	t_list	*change_value_back(char *value, t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (env == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (value)
		tmp->value = value;
	tmp->kind = 0;
	return (env);
}

/*
** return the name of a env's variable.
*/

static	char	*get_name(char *str)
{
	size_t	size;
	char	*name;

	size = 0;
	while (str && str[size] && str[size] != '=')
		++size;
	name = ft_strldup(str, size);
	if (!name)
		return (NULL);
	return (name);
}

/*
** return the value of a env's variable.
*/

static	char	*get_value(char *str)
{
	int		i;
	size_t	size;
	char	*value;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (i != 0 && str[i - 1] == '=')
			break ;
		++i;
	}
	size = ft_strlen(str + i);
	value = ft_strldup(str + i, size);
	if (!value)
		return (NULL);
	return (value);
}

/*
** return a list with env's variables.
** The list has two variables :
** - name (variable's names).
** - value (variable's assignements).
*/

t_list	*get_env(t_list *env, int *ret)
{
	int			i;
	extern char	**environ;
	char		*name;
	char		*value;

	i = 0;
	while (environ[i])
	{
		name = NULL;
		value = NULL;
		name = get_name(environ[i]);
		if (!name)
			return (env_failed(&ret, env, name, value));
		env = add_name(name, env);
		if (!env)
			return (env_failed(&ret, env, name, value));
		value = get_value(environ[i]);
		if (!value)
			return (env_failed(&ret, env, name, value));
		env = change_value_back(value, env);
		if (!env)
			return (env_failed(&ret, env, name, value));
		++i;
	}
	return (env);
}
