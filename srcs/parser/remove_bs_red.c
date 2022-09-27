/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_bs_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:13 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:44:14 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	size_t	len_new(char *str)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str && str[i])
	{
		if (str[i] == '\\' && c_is_escape(i, str) == NO)
			;
		else
			++size;
		++i;
	}
	return (size);
}

static	char	*dup_without_backslash(char *str, size_t size)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == '\\' && c_is_escape(i, str) == NO)
			;
		else
		{
			new[j] = str[i];
			++j;
		}
		++i;
	}
	new[j] = '\0';
	return (new);
}

static	char	*rm_backslash_token(char *str)
{
	char	*new;
	size_t	size;

	size = len_new(str);
	new = dup_without_backslash(str, size);
	free(str);
	return (new);
}

static	int	parse_cmd(t_list *red)
{
	t_list	*tmp;

	tmp = red;
	while (red)
	{
		if (c_is_str('\\', red->token) == YES)
		{
			red->token = rm_backslash_token(red->token);
			if (!red->token)
				return (-1);
		}
		red = red->next;
	}
	red = tmp;
	return (0);
}

t_cli	*remove_bs_red(t_cli *cli)
{
	t_cli	*tmp;

	tmp = cli;
	while (cli)
	{
		if (parse_cmd(cli->red))
			return (free_cli(tmp));
		cli = cli->next;
	}
	cli = tmp;
	return (cli);
}
