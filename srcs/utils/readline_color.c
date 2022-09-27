/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:20 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:21 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*readline_color(char *prompt_nc, char *color, char *nc)
{
	char	*prompt;
	char	*tmp;
	char	*read;

	if (prompt_nc == NULL || color == NULL)
		return (NULL);
	prompt = ft_strjoin(color, prompt_nc);
	if (prompt == NULL)
		return (NULL);
	tmp = prompt;
	prompt = ft_strjoin(prompt, nc);
	free(tmp);
	read = readline(prompt);
	free(prompt);
	return (read);
}
