/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:39:19 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:39:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_export(void)
{
	t_list	*tmp;
	t_list	*join;

	join = join_env_in_tab(g_glob.env);
	if (join == NULL)
		return (-1);
	lst_sort_token(join);
	tmp = join;
	while (join)
	{
		ft_printf("%s\n", join->token);
		join = join->next;
	}
	join = tmp;
	lst_free(join);
	g_glob.ret = 0;
	return (1);
}
