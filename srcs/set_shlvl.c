/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:58:34 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/04 19:58:35 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	add_one_to_shlvl(int val)
{
	t_list	*tmp;
	char	*value;

	tmp = g_glob.env;
	while (g_glob.env && ft_strcmp(g_glob.env->name, "SHLVL") != 0)
		g_glob.env = g_glob.env->next;
	free(g_glob.env->value);
	g_glob.env->value = NULL;
	value = ft_itoa(val);
	if (value != NULL)
		g_glob.env->value = ft_strdup(value);
	free(value);
	if (g_glob.env->value == NULL)
	{
		g_glob.env = tmp;
		return (-1);
	}
	g_glob.env = tmp;
	return (0);
}

static	int	reset_shlvl(int value)
{
	t_list	*tmp;

	tmp = g_glob.env;
	ft_putstr_fd("minishell: warning: shell level too high (", 2);
	ft_putnbr_fd(value + 1, 2);
	ft_putstr_fd("), initializer to 1\n", 2);
	while (g_glob.env && ft_strcmp(g_glob.env->name, "SHLVL") != 0)
		g_glob.env = g_glob.env->next;
	free(g_glob.env->value);
	g_glob.env->value = ft_strdup("1");
	if (g_glob.env->value == NULL)
	{
		g_glob.env = tmp;
		return (-1);
	}
	g_glob.env = tmp;
	return (0);
}

static	int	no_shlvl_var(void)
{
	char	*name;
	char	*value;

	name = ft_strdup("SHLVL");
	if (name == NULL)
		return (-1);
	value = ft_strdup("1");
	if (value == NULL)
	{
		free(name);
		return (-1);
	}
	g_glob.env = env_add_back(name, value, 0, g_glob.env);
	if (g_glob.env == NULL)
		return (-1);
	return (0);
}

int	set_shlvl(void)
{
	char	*value;
	int		val;

	value = our_getenv("SHLVL");
	if (value == NULL)
		return (no_shlvl_var());
	val = ft_atoi(value);
	if (val >= 999)
		return (reset_shlvl(val));
	else
		return (add_one_to_shlvl(val + 1));
}
