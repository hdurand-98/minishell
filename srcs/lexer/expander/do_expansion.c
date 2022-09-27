/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:24 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:25 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_var_exist(char *name)
{
	t_list	*tmp;

	tmp = g_glob.env;
	while (g_glob.env)
	{
		if (ft_strcmp(g_glob.env->name, name) == 0)
		{
			g_glob.env = tmp;
			return (YES);
		}
		g_glob.env = g_glob.env->next;
	}
	g_glob.env = tmp;
	return (NO);
}

static	t_list	*add_back_token(char *str, int kind, t_list *lex)
{
	char	*token;

	token = NULL;
	if (c_is_str('$', str) == YES && kind != WD_S_QUOTE)
	{
		if (str[1] == '?')
			token = ft_itoa(g_glob.ret);
		else if (str[0] == '$' && str[1] == '\0')
			token = ft_strdup("$");
		else
		{
			if (is_var_exist(str + 1) == NO)
				return (lex);
			return (lex = token_expansion(str + 1, lex));
		}
	}
	else
		token = ft_strdup(str);
	if (token == NULL)
		return (NULL);
	lex = lst_add_back(token, kind, lex);
	if (lex == NULL)
		return (NULL);
	return (lex);
}

t_list	*do_expansion(t_list *lex)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = lex;
	while (lex)
	{
		if (lex->kind == WD_D_QUOTE && c_is_str('$', lex->token) == YES)
			new = add_back_token_double_quote(lex->token, new);
		else
			new = add_back_token(lex->token, lex->kind, new);
		lex = lex->next;
	}
	lex = tmp;
	lst_free(lex);
	return (new);
}
