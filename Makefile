# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 10:45:35 by tallaire          #+#    #+#              #
#    Updated: 2021/09/30 20:10:14 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m


NAME	=	minishell

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c -g3

TFLAGS	=	-lncurses

SRC		+=	add_back_token_double_quote.c
SRC		+=	add_sep_tok_for_red.c
SRC		+=	built_ins.c
SRC		+=	c_is_escape.c
SRC		+=	cat_quote.c
SRC		+=	cd.c
SRC		+=	cd_utils.c
SRC		+=	check_ambiguous_red.c
SRC		+=	check_gram_char.c
SRC		+=	check_name_and_value.c
SRC		+=	checker.c
SRC		+=	clean_dollars.c
SRC		+=	dev_quote.c
SRC		+=	do_cd.c
SRC		+=	do_cd_minus.c
SRC		+=	do_expansion.c
SRC		+=	do_export.c
SRC		+=	do_sigint.c
SRC		+=	do_sigquit.c
SRC		+=	echo.c
SRC		+=	empty_home_value.c
SRC		+=	env_add_back.c
SRC		+=	env.c
SRC		+=	err_msg_ambiguous_red.c
SRC		+=	exit.c
SRC		+=	expand_if_we_need_to.c
SRC		+=	expander.c
SRC		+=	expander_ambiguous.c
SRC		+=	export.c
SRC		+=	export_utils.c
SRC		+=	free_cli.c
SRC		+=	free_tab_string.c
SRC		+=	ft_perror.c
SRC		+=	ft_split_slash.c
SRC		+=	get_cli.c
SRC		+=	get_cli_utils.c
SRC		+=	get_env.c
SRC		+=	get_env_utils.c
SRC		+=	get_redirect.c
SRC		+=	go_home.c
SRC		+=	go_to_next_quote.c
SRC		+=	handle_var.c
SRC		+=	is_arg_exit_valid.c
SRC		+=	is_quote.c
SRC		+=	is_quote_even.c
SRC		+=	kind_cli.c
SRC		+=	len_first_quote.c
SRC		+=	lexer.c
SRC		+=	lst_add_back.c
SRC		+=	lst_add_front.c
SRC		+=	lst_dup.c
SRC		+=	lst_free.c
SRC		+=	lst_free_env.c
SRC		+=	lst_new.c
SRC		+=	lst_print.c
SRC		+=	lst_print_cli.c
SRC		+=	lst_rm_back.c
SRC		+=	lst_rm_front.c
SRC		+=	lst_rm_next.c
SRC		+=	lst_size.c
SRC		+=	lst_sort_token.c
SRC		+=	lst_to_string.c
SRC		+=	main.c
SRC		+=	make_a_cli.c
SRC		+=	master.c
SRC		+=	new_proc_utils.c
SRC		+=	new_process.c
SRC		+=	normal_cmd.c
SRC		+=	our_getenv.c
SRC		+=	parser.c
SRC		+=	piped_cmd.c
SRC		+=	print_env.c
SRC		+=	print_export.c
SRC		+=	print_stx_err.c
SRC		+=	pwd.c
SRC		+=	readline_color.c
SRC		+=	redir.c
SRC		+=	redir_in.c
SRC		+=	remove_bs_red.c
SRC		+=	rm_ambiguous_red_from_cli_red.c
SRC		+=	rm_quote.c
SRC		+=	rm_sep_tok.c
SRC		+=	rm_sep_token.c
SRC		+=	rm_red_from_cmd.c
SRC		+=	set_shlvl.c
SRC		+=	successive_token.c
SRC		+=	token_expander.c
SRC		+=	token_expansion.c
SRC		+=	token_len.c
SRC		+=	unset.c
SRC		+=	where_is_c.c
SRC		+=	find_path.c
SRC		+=	get_next_line_bis.c

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/built_ins/
vpath %.c srcs/built_ins/cd/
vpath %.c srcs/built_ins/exit/
vpath %.c srcs/built_ins/export/
vpath %.c srcs/get_env/
vpath %.c srcs/lexer/
vpath %.c srcs/lexer/checking/
vpath %.c srcs/lexer/checking/ambiguous_red/
vpath %.c srcs/lexer/expander/
vpath %.c srcs/lexer/token_len/
vpath %.c srcs/list/
vpath %.c srcs/parser/
vpath %.c srcs/parser/dev_quote/
vpath %.c srcs/signal/
vpath %.c srcs/utils/
vpath %.c srcs/execute/

OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

LIBFT_NAME	=	libft.a

HEADER_NAME	=	minishell.h

LIB_PATH	=	./.lib

HEADER_PATH	=	./include

LIBFT_PATH	=	./libft

LIBFT_SRC	=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT		=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

all: $(NAME)

$(NAME): $(LIB_PATH) $(LIBFT_SRC) $(LIBFT) $(OBJ_PATH) $(OBJ)
	@$(CC) -I$(HEADER_PATH)/ -lreadline -o $(NAME) $(OBJ) $(LIBFT) $(TFLAGS)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) -I$(HEADER_PATH)/ $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@$(CP) $(LIBFT_SRC) $(LIB_PATH)

$(LIBFT_SRC):
	@(cd $(LIBFT_PATH) && $(MAKE))

$(LIB_PATH):
	@mkdir $(LIB_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) clean)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) fclean)

re: fclean all
