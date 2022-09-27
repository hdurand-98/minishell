/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:44:10 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/30 19:21:55 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cli	*parser(t_list *lex)
{
	t_cli	*cli;

	cli = NULL;
	cli = get_cli(lex);
	if (cli)
		cli = dev_quote(cli);
	if (cli)
		cli = get_redirect(cli);
	if (cli)
		rm_red_from_cmd(cli);
	if (cli)
		cli = remove_bs_red(cli);
	if (cli)
		cli = rm_sep_token(cli);
	if (cli)
		cli = kind_cli(cli);
	return (cli);
}
