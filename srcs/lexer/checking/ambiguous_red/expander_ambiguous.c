/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_ambiguous.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:31 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:32 by tallaire         ###   ########.fr       */
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

static	int	is_several_word(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && c_is_str(str[i], C_SEP_TOK) == YES)
		++i;
	while (str[i] && c_is_str(str[i], C_SEP_TOK) == NO)
		++i;
	while (str[i] && c_is_str(str[i], C_SEP_TOK) == YES)
		++i;
	if (str[i] != '\0')
		return (YES);
	return (NO);
}

static	char	*expand_token(char *str)
{
	char	*token;

	token = our_getenv(str + 1);
	if (is_several_word(token) == YES)
		return (str);
	if (token == NULL)
		return (str);
	token = ft_strdup(token);
	if (token == NULL)
		return (str);
	free(str);
	return (token);
}

t_list	*expander_ambiguous(t_list *lex)
{
	t_list	*tmp;

	tmp = lex;
	while (lex)
	{
		if (is_var_exist(lex->token + 1) == YES)
			lex->token = expand_token(lex->token);
		lex = lex->next;
	}
	return (tmp);
}
