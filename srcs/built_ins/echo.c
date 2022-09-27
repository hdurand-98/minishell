/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:39:09 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:39:11 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_an_echoption(char *token, int *n)
{
	int	i;

	i = 0;
	if (token && token[0] == '-' && token[1] == 'n')
	{
		i = 2;
		while (token && token[i] == 'n')
			i++;
	}
	if (token[i] == 0 && i != 0)
	{
		*n = 1;
		return (1);
	}
	else
		return (0);
}

int	ft_echo(t_list *cmd)
{
	int	noption;

	noption = 0;
	if (cmd != NULL)
	{
		while (cmd != NULL
			&& ft_is_an_echoption(cmd->token, &noption) == 1)
			cmd = cmd->next;
		while (cmd != NULL)
		{
			ft_putstr_fd(cmd->token, 1);
			if (cmd->next != NULL)
				ft_putstr_fd(" ", 1);
			cmd = cmd->next;
		}
	}
	if (noption == 0)
		ft_putstr_fd("\n", 1);
	return (1);
}
