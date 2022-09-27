/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:57 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/30 20:27:41 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <errno.h>
# include <curses.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft.h"
# include "./color.h"
# include "./list.h"

# define PROMPT			"Echecs $"
# define PROMPT_COLOR 	PURPLE
# define YES			0
# define NO				(-1)

# define BACKSLASH		NO

# define EXEC_WORD		10
# define WD_TOK			11

# define C_GRAM			"|>< \"\'\t"
# define C_SEP_CMD		"|"
# define WD_SEP_CMD		12
# define C_RED			"<>"
# define WD_RED			13
# define C_SEP_TOK		" \t"
# define WD_SEP_TOK		14
# define C_QUOTE		"\'\""
# define C_S_QUOTE		"\'"
# define WD_S_QUOTE		15
# define C_D_QUOTE		"\""
# define WD_D_QUOTE		16
# define WD_VAR_AFF		17
# define WD_VAR			18

# define CLI_SEP		20
# define CLI_CMD		21
# define CLI_VAR		22
# define CLI_NO_CMD	23

# define R_STDIN		100
# define R_STDOUT	101
# define R_STDOUT_APP 102
# define R_HEREDOC		103
# define R_HEREDOC_Q	104

# define NO_SEP			0
# define PIPE			1

typedef struct s_glob
{
	int		sig_quit;
	int		ret;
	int		aff_prompt;
	int		red;
	int		ispipe;
	t_list	*env;
	t_cli	*head;
}		t_glob;

t_glob		g_glob;

int			set_shlvl(void);

/*
** GET_ENV
*/

t_list		*env_add_back(char *name, char *value, int kind, t_list *arg);
t_list		*env_failed(int **ret, t_list *env, char *name, char *value);
t_list		*get_env(t_list *env, int *ret);

/*
** LEXER
*/

int			check_ambiguous_red(t_list *lex);
int			check_gram_char(t_list *lex);
int			checker(t_list *lex);
int			is_quote(int i, char *str);
int			is_quote_even(t_list *lex);
int			len_first_quote(char *str, int size);
int			make_a_cli(t_list *cmd);
int			successive_token(t_list *lex);
size_t		token_len(size_t y, char *str);
t_cli		*rm_ambiguous_red_from_cli_red(t_cli *cli);
t_list		*add_back_token_double_quote(char *str, t_list *lex);
t_list		*add_sep_tok_for_red(t_list *lex);
t_list		*clean_dollars(t_list *lex);
t_list		*do_expansion(t_list *lex);
t_list		*expand_if_we_need_to(t_list *lex);
t_list		*expander_ambiguous(t_list *lex);
t_list		*expander(t_list *lex);
t_list		*lexer(char *line, t_list *lex);
t_list		*token_expander(char *str, int kind, t_list *lex);
t_list		*token_expansion(char *str, t_list *lex);
void		err_msg_ambiguous_red(t_cli *cli);

/*
** PARSER
*/

char		*rm_backslash(char *str);
char		*rm_quote(char *str);
t_cli		*clean_cli(t_cli *cli);
t_cli		*parser(t_list *lex);
t_cli		*dev_quote(t_cli *cli);
t_cli		*get_cli(t_list *lex);
t_cli		*get_cli_continued(t_list *lex, t_cli *cli,
				t_list *cmd, t_list *dup);
t_cli		*get_redirect(t_cli *cli);
t_cli		*kind_cli(t_cli *cli);
t_cli		*remove_bs(t_cli *cli);
t_cli		*remove_bs_red(t_cli *cli);
t_cli		*rm_red_from_cmd(t_cli *cli);
t_cli		*rm_sep_cmd(t_cli *cli);
t_cli		*rm_sep_token(t_cli *cli);
t_list		*cat_quote(t_list *cmd);
t_list		*get_var(char *str);
t_list		*rm_sep_tok(t_list *lex);
t_list		*lst_dup_cli(t_list *list, int *stop);
void		print_stx_err(char *str, int kind);

/*
** SIGNAL
*/

void		do_sigint(int signum);
void		do_sigquit(int signum);
void		do_sigign(int signum);

/*
** UTILS
*/

char		*readline_color(char *prompt_nc, char *color, char *nc);
char		*our_getenv(char *str);
char		**ft_split_slash(char *str, char *sep);
int			c_is_escape(int c, char *str);
int			is_quote_pair(char *str);
int			where_is_c(char c, char *str);
int			go_to_next_quote(char *str, int i, char quote);
t_list		*init_kind(t_list *env);
void		ft_perror(const char *str);
void		print_env(void);
void		*free_tab_string(char **str);
int			get_next_line_bis(int fd, char **line);

/*
** EXECUTE
*/

char		**ft_cmd_to_tab(t_list *cmd, int depth);
int			ft_execute_prog(t_cli *cli);
int			ft_master(t_cli *cli);
int			is_a_built_in(t_cli *cli);
void		ft_freetab(char **av);
int			ft_redir(t_list *red);
void		ft_exit_proc(char **tabl, int fd);
void		ft_print_crdmp(int sig);
void		ft_child_proc(t_cli *cli);
void		ft_duped(int *piped, int piped_fd);
void		ft_normal_cmd(int *piped, t_cli **cli, int **fdptab, int *i);
void		ft_piped_cmd(int *piped, t_cli **cli, int **fdptab, int *i);
int			ft_return(int i, int fd, char *str);
int			ft_left_or_right(int kind);
int			ft_red_in(t_list **red);
char		**ft_env_to_tab(t_list *cmd, int depth);
int			ft_wrong_fd(char *str);
t_list		*ft_find_path(t_list *cmd);
char		*ft_double_strjoin(char *str1, char *str2, char *str3);
void		ft_exec_failed(char **env, char **paths, char *str, char **av);
void		ft_free_proc(t_cli *cli);
int			ft_contains(char *str, char c);

/*
** BUILT_INS
*/

t_list		*join_env_in_tab(t_list *env);
int			check_name_and_value(char *name, char *value);
int			do_cd(char *path);
int			do_cd_minus(char *path);
int			do_export(char *name, char *value, int kind);
int			empty_home_value(char *home_path);
int			ft_echo(t_list *cmd);
int			ft_cd(t_list *cmd);
int			ft_pwd(t_list *cmd);
int			ft_export(t_list *cmd);
int			ft_unset(t_list *cmd);
int			ft_env(t_list *cmd);
int			ft_exit(t_list *cmd);
int			go_home(void);
int			handle_var(t_list *cmd);
int			is_arg_exit_valid(char *str);
int			is_path_valid(char *str);
int			print_err_cd(char *str, char *old_path);
int			print_export(void);

void		minishell(char *read, t_list *lex, t_cli *cli);

#endif
