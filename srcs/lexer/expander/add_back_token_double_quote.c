/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_token_double_quote.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:18 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:42:19 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*rm_double_quote(char *str)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*new;

	i = 2;
	j = 0;
	size = ft_strlen(str) - 3 + 1;
	new = malloc(size);
	if (new == NULL)
		return (NULL);
	while (str[i] && str[i] != '\"')
	{
		new[j] = str[i];
		++i;
		++j;
	}
	new[j] = '\0';
	return (new);
}

static	int	is_var_exist(char *name)
{
	t_list	*tmp;
	char	*word;

	tmp = g_glob.env;
	word = rm_double_quote(name);
	while (g_glob.env && word)
	{
		if (ft_strcmp(g_glob.env->name, word) == 0)
		{
			g_glob.env = tmp;
			free(word);
			return (YES);
		}
		g_glob.env = g_glob.env->next;
	}
	free(word);
	g_glob.env = tmp;
	return (NO);
}

static	char	*token_expansion_quote(char *str)
{
	char	*token;
	char	*word;

	word = rm_double_quote(str);
	if (word == NULL)
		return (NULL);
	token = our_getenv(word);
	free(word);
	token = ft_strdup(token);
	return (token);
}

t_list	*add_back_token_double_quote(char *str, t_list *lex)
{
	char	*token;
	int		kind;

	token = NULL;
	kind = WD_TOK;
	if (str[2] == '?')
		token = ft_itoa(g_glob.ret);
	else if (str[1] == '$' && c_is_alnum(str[2]) == NO)
		token = ft_strdup("$");
	else
	{
		if (is_var_exist(str) == NO)
		{
			token = ft_strdup("\"\"");
			kind = WD_D_QUOTE;
		}
		else
			token = token_expansion_quote(str);
	}
	if (token == NULL)
		return (NULL);
	lex = lst_add_back(token, kind, lex);
	return (lex);
}
