/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:38:25 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:38:26 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*change_value(char *value, char *old)
{
	char	*new;

	new = ft_strdup(value);
	if (new == NULL)
		return (NULL);
	free(old);
	return (new);
}

static	int	modify_variable(char *name, char *value, int kind)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(name, g_glob.env->name) == YES)
		{
			g_glob.env->value = change_value
				(value, g_glob.env->value);
			if (g_glob.env->value == NULL)
				return (-1);
			g_glob.env->kind = kind;
			g_glob.env = tmp;
			return (0);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (0);
}

/*
** check if the variable's name (str) already exist
** in the env of this minishell (g_glob.env).
*/

static	int	does_name_exist(char *str)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(str, g_glob.env->name) == YES)
		{
			g_glob.env = tmp;
			return (YES);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (NO);
}

/*
** add a variable in the env of this minishell.
*/

static	int	add_var(char *name, char *value, int kind)
{
	char	*dup_name;
	char	*dup_value;

	dup_name = ft_strdup(name);
	if (dup_name == NULL)
		return (-1);
	dup_value = ft_strdup(value);
	if (dup_value == NULL)
		return (-1);
	g_glob.env = env_add_back(dup_name, dup_value, kind, g_glob.env);
	if (g_glob.env == NULL)
		return (-1);
	return (0);
}

int	do_export(char *name, char *value, int kind)
{
	if (does_name_exist(name) == YES)
		return (modify_variable(name, value, kind));
	else
		return (add_var(name, value, kind));
	return (0);
}
