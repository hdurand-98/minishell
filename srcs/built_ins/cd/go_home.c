/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:38:10 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:38:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*dup_env_var(char *name)
{
	char	*var;
	char	*dup;

	dup = NULL;
	var = our_getenv(name);
	if (var == NULL)
		return (NULL);
	dup = ft_strdup(var);
	if (dup == NULL)
		return (NULL);
	return (dup);
}

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

static	int	handle_var_env(void)
{
	char	*home_path;
	char	*cpath;
	int		ret;

	ret = 0;
	home_path = dup_env_var("HOME");
	cpath = dup_env_var("PWD");
	if (home_path == NULL || cpath == NULL)
	{
		free(home_path);
		free(cpath);
		return (-1);
	}
	ret = modify_variable("PWD", home_path, 0);
	ret = modify_variable("OLDPWD", cpath, 0);
	free(home_path);
	free(cpath);
	if (ret == (-1))
		return (-1);
	return (0);
}

int	go_home(void)
{
	char	*home_path;
	int		ret;

	ret = 0;
	home_path = dup_env_var("HOME");
	if (home_path == NULL)
	{
		ft_printf("minishell: cd: HOME not set\n");
		g_glob.ret = 1;
		return (-1);
	}
	else if (home_path[0] == '\0')
		return (empty_home_value(home_path));
	ret = chdir(home_path);
	if (ret == (-1))
	{
		g_glob.ret = 1;
		free(home_path);
		return (-1);
	}
	free(home_path);
	if (handle_var_env())
		return (-1);
	g_glob.ret = 0;
	return (1);
}
