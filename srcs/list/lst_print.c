/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:20 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:43:21 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_print(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%s%d |%s%s\n", CYAN, list->kind, list->token, NC);
		++i;
		list = list->next;
	}
	printf("%s      NULL%s\n", YELLOW, NC);
}
