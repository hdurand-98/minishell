/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:37:56 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:37:57 by tallaire         ###   ########.fr       */
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

static	int	go_to_old_path_continued(char *old_pwd,
	char *curd, char *name_var, int ret)
{
	curd = ft_strdup(name_var);
	ret = modify_variable("OLDPWD", curd, 0);
	ret = modify_variable("PWD", old_pwd, 0);
	ft_putstr_fd(old_pwd, 2);
	ft_putstr_fd("\n", 2);
	free(old_pwd);
	free(curd);
	if (ret)
		return (-1);
	g_glob.ret = 0;
	return (1);
}

static	int	go_to_old_path(void)
{
	int		ret;
	char	*name_var;
	char	*old_pwd;
	char	*curd;

	ret = 0;
	old_pwd = NULL;
	curd = NULL;
	name_var = our_getenv("OLDPWD");
	if (name_var == NULL)
		return (print_err_cd("OLDPWD", old_pwd));
	old_pwd = ft_strdup(name_var);
	if (chdir(old_pwd))
		return (-1);
	name_var = our_getenv("PWD");
	if (name_var == NULL)
		return (print_err_cd("PWD", old_pwd));
	return (go_to_old_path_continued(old_pwd, curd, name_var, ret));
}

int	do_cd_minus(char *path)
{
	if (is_path_valid(path) == NO)
	{
		ft_printf("bash: cd: %c%c : none valid option\n",
			path[0], path[1]);
		g_glob.ret = 2;
		return (-1);
	}
	if (path[0] == '-' && path[1] == '\0')
		return (go_to_old_path());
	else if (path[0] == '-' && path[1] == '-' && path[2] == '\0')
		g_glob.ret = 0;
	return (1);
}
