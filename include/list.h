/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:54 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/16 10:45:55 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	char				*token;
	char				*name;
	char				*value;
	int					kind;
	struct s_list		*next;
}		t_list;

typedef struct s_cli
{
	t_list			*cmd;
	t_list			*red;
	int				kind;
	int				sep;
	struct s_cli	*next;
}			t_cli;

char	*lst_to_string(t_list *lst);
t_cli	*free_cli(t_cli *cli);
size_t	lst_size(t_list *list);
t_list	*lst_new(void);
t_list	*lst_add_front(char *token, int kind, t_list *list);
t_list	*lst_add_back(char *token, int kind, t_list *list);
t_list	*lst_dup(t_list *list);
t_list	*lst_rm_front(t_list *list);
t_list	*lst_rm_back(t_list *list);
t_list	*lst_rm_next(t_list *list);
t_list	*lst_free(t_list *list);
t_list	*lst_free_env(t_list *list);
void	lst_print(t_list *list);
void	lst_print_cli(t_cli *cli);
void	lst_sort_token(t_list *list);

#endif
