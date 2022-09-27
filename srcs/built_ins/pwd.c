/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:02:54 by user42            #+#    #+#             */
/*   Updated: 2021/09/30 19:30:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_pwd_var(void)
{
	char	*pwd;

	pwd = our_getenv("PWD");
	if (pwd == NULL)
		return (-1);
	ft_printf("%s\n", pwd);
	return (1);
}

int	ft_pwd(t_list *cmd)
{
	char	*path;
	size_t	size;

	size = lst_size(cmd);
	path = getcwd(NULL, 0);
	if (path == NULL && errno == 2)
		return (print_pwd_var());
	if (path == NULL)
	{
		ft_perror("Echec: pwd:");
		return (1);
	}
	ft_printf("%s\n", path);
	free(path);
	g_glob.ret = 0;
	return (1);
}
