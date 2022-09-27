/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:05 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:06 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lst_free_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (env)
	{
		tmp = env;
		free(env->name);
		free(env->value);
		env = env->next;
		free(tmp);
	}
	return (NULL);
}
