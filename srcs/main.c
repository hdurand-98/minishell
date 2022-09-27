/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:28 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/30 20:09:44 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell(char *read, t_list *lex, t_cli *cli)
{
	while (1)
	{
		if (read == NULL)
			read = readline_color("Echecs $ ", PROMPT_COLOR, NC);
		if (read == NULL)
			ft_exit(NULL);
		if (read)
			lex = lexer(read, lex);
		add_history(read);
		free(read);
		if (lex)
			cli = parser(lex);
		g_glob.head = cli;
		lex = lst_free(lex);
		g_glob.aff_prompt = NO;
		signal(SIGQUIT, do_sigquit);
		if (cli)
			ft_master(cli);
		signal(SIGQUIT, SIG_IGN);
		g_glob.aff_prompt = YES;
		cli = free_cli(cli);
		g_glob.head = cli;
		read = NULL;
	}
}

int	main(void)
{
	t_list	*lex;
	t_cli	*cli;
	char	*read;
	int		ret;

	ret = 0;
	lex = lst_new();
	signal(SIGINT, do_sigint);
	signal(SIGQUIT, SIG_IGN);
	ft_bzero(&g_glob, sizeof(t_glob));
	cli = NULL;
	read = NULL;
	g_glob.env = get_env(g_glob.env, &ret);
	set_shlvl();
	if (g_glob.env == NULL && ret == (-1))
		return (0);
	minishell(read, lex, cli);
	return (0);
}
