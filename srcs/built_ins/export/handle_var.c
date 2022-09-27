/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:39:07 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/30 20:05:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	free_var(char *name, char *value, t_list **cmd, t_list *tmp)
{
	if (name != NULL)
		free(name);
	if (value != NULL)
		free(value);
	if (*cmd != NULL && tmp == NULL)
		*cmd = tmp;
	return (-1);
}

static	char	*get_name_var(char *str)
{
	size_t	i;
	char	*name;

	i = 0;
	name = NULL;
	while (str && str[i] && str[i] != '=')
		++i;
	name = malloc(sizeof(char) * i + 1);
	if (name == NULL)
		return (NULL);
	i = 0;
	while (str && str[i] && str[i] != '=')
	{
		name[i] = str[i];
		++i;
	}
	name[i] = '\0';
	return (name);
}

static	char	*get_value_var(char *str, int *kind)
{
	char	*value;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '=')
		++i;
	if (str[i] == '=')
		++i;
	else
		*kind = 1;
	value = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (value == NULL)
		return (NULL);
	while (str && str[i])
	{
		value[j] = str[i];
		++i;
		++j;
	}
	value[j] = '\0';
	return (value);
}

static	int	handle_var_help(t_list *cmd, int kind, char *value, char *name)
{
	t_list	*tmp;

	tmp = cmd;
	g_glob.ret = 0;
	while (cmd)
	{
		name = NULL;
		value = NULL;
		kind = 0;
		name = get_name_var(cmd->token);
		value = get_value_var(cmd->token, &kind);
		if (value == NULL || name == NULL)
			return (free_var(name, value, &cmd, tmp));
		if (check_name_and_value(name, value) == YES)
		{
			if (do_export(name, value, kind) == (-1))
				return (free_var(name, value, &cmd, tmp));
			free_var(name, value, &cmd, tmp);
		}
		else
			free_var(NULL, value, &cmd, tmp);
		cmd = cmd->next;
	}
	cmd = tmp;
	return (1);
}

int	handle_var(t_list *cmd)
{
	int		kind;
	char	*value;
	char	*name;

	kind = 0;
	name = NULL;
	value = NULL;
	if (handle_var_help(cmd, kind, value, name) == (-1))
		return (-1);
	return (1);
}
