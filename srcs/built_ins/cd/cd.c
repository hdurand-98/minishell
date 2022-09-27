/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:10:39 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 19:25:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_list *cmd)
{
	size_t	size;

	size = lst_size(cmd);
	if (size == 0)
		return (go_home());
	else if (size > 1)
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
		g_glob.ret = 1;
		return (-1);
	}
	else
	{
		if (cmd->token[0] == '-')
			return (do_cd_minus(cmd->token));
		return (do_cd(cmd->token));
	}
	return (1);
}
