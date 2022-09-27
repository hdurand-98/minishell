/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:21 by hdurand           #+#    #+#             */
/*   Updated: 2021/09/16 11:40:23 by hdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wrong_fd(char *str)
{
	g_glob.ret = 1;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	return (0);
}

void	ft_free_read(char *read)
{
	free(read);
	g_glob.aff_prompt = NO;
	return ;
}

void	ft_heredoc(char *delim)
{
	int		fd;
	char	*read;

	signal(SIGQUIT, do_sigign);
	fd = open("/tmp/here-document", O_CREAT | O_TRUNC | O_WRONLY, 0666);
	g_glob.aff_prompt = YES;
	while (1 && g_glob.ret != 130)
	{
		get_next_line_bis(0, &read);
		if (read == NULL)
		{
			ft_putstr_fd
("minishell : warning : here-document delimited by end of file\n", 2);
			return (ft_free_read(read));
		}
		else if (ft_strncmp(read, delim, ft_strlen(delim)) == 0)
			return (ft_free_read(read));
		else
		{
			write(fd, read, ft_strlen(read));
			free(read);
		}
	}
	g_glob.aff_prompt = NO;
	close(fd);
}

int	ft_red_in_loop(t_list *red)
{
	int	fd;

	if (red->kind == R_STDIN)
	{
		fd = open(red->token, O_RDONLY);
		if (fd == -1)
			return (ft_wrong_fd(red->token));
		close(fd);
	}
	else if (red->kind == R_HEREDOC)
		ft_heredoc(red->token);
	return (1);
}

int	ft_red_in(t_list **red)
{
	int	fd;

	while ((*red)->next != NULL && ft_left_or_right((*red)->next->kind) == 0)
	{
		if (ft_red_in_loop((*red)) == 0)
			return (0);
		(*red) = (*red)->next;
	}
	if ((*red)->kind == R_HEREDOC)
	{
		ft_heredoc((*red)->token);
		if (g_glob.ret != 130)
			fd = open("/tmp/here-document", O_RDONLY);
		else
			return (0);
	}
	else
		fd = open((*red)->token, O_RDONLY);
	if (fd == -1)
		return (ft_wrong_fd((*red)->token));
	if (dup2(fd, 0) == -1)
		return (ft_return(0, fd, (*red)->token));
	close(fd);
	(*red) = (*red)->next;
	return (1);
}
