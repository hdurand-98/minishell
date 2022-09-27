/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stx_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:41:58 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	print_err(char *str)
{
	ft_printf("minishell : unexpected syntax's error ");
	ft_printf("\" %s \"\n", str);
}

static	void	print_sep_cmd_err(char *str)
{
	if (str[0] == ';')
	{
		if (ft_strlen(str) > 2)
			print_err(";;");
		else
			print_err(str);
	}
	else if (str[0] == '|')
	{
		if (ft_strlen(str) > 2)
			print_err("||");
		else
			print_err(str);
	}
}

static	void	print_red_err(char *str)
{
	if (str[0] == '<')
	{
		if (ft_strlen(str) > 2)
			print_err("<<");
		else
			print_err(str);
	}
	else if (str[0] == '>')
	{
		if (ft_strlen(str) > 2)
			print_err(">>");
		else
			print_err(str);
	}
}

void	print_stx_err(char *str, int kind)
{
	if (kind == WD_SEP_CMD)
		print_sep_cmd_err(str);
	else if (kind == WD_RED)
		print_red_err(str);
	else
		print_err(str);
}
