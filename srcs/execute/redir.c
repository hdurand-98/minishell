/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:30 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:40:31 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_return(int i, int fd, char *str)
{
	if (fd != -1 && i == 0)
		close(fd);
	else if (i == 1)
	{
		if (dup2(fd, 1) == -1)
		{
			close(fd);
			ft_wrong_fd(str);
		}
		close(fd);
	}
	else
	{
		if (ft_strcmp(str, "\"\"") == 0)
			ft_wrong_fd("");
		else
			ft_wrong_fd(str);
	}
	return (i);
}

int	ft_red_out(t_list **red)
{
	int	duped;

	duped = 0;
	while ((*red) != NULL && (*red)->kind != R_STDIN)
	{
		if (duped != 0)
			close(duped);
		if (ft_strcmp((*red)->token, "\"\"") == 0
			|| ft_strcmp((*red)->token, "\'\'") == 0)
			duped = open("\0", O_TRUNC | O_WRONLY, 0666);
		else if ((*red)->kind == R_STDOUT)
			duped = open((*red)->token, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		else if ((*red)->kind == R_STDOUT_APP)
			duped = open((*red)->token, O_CREAT | O_APPEND | O_WRONLY, 0666);
		if (duped == -1)
			return (ft_return(0, duped, (*red)->token));
		(*red) = (*red)->next;
	}
	if ((*red) != NULL && (*red)->kind == R_STDIN)
		return (ft_return(1, duped, NULL));
	if (dup2(duped, 1) == -1)
		return (ft_return(0, duped, (*red)->token));
	if (duped != 0)
		close(duped);
	return (1);
}

int	ft_left_or_right(int kind)
{
	if (kind == R_STDIN)
		return (0);
	else if (kind == R_HEREDOC)
		return (0);
	else if (kind == R_STDOUT)
		return (1);
	else if (kind == R_STDOUT_APP)
		return (1);
	return (-1);
}

int	ft_redir(t_list *red)
{
	int	ret;

	while (red != NULL)
	{
		if (ft_left_or_right(red->kind) == 1)
			ret = ft_red_out(&red);
		else
			ret = ft_red_in(&red);
		if (ret == 0)
			return (ret);
	}
	return (1);
}
