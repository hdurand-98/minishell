# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:39:06 by tallaire          #+#    #+#              #
#    Updated: 2021/05/31 15:52:39 by tallaire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

RM = rm -rf

CFLAGS = -Werror -Wextra -Wall -c

HEADER = ./includes/libft.h

################################
############ COLORS ############
################################

C_GREEN		=	\033[0;32m
C_RED		=	\033[0;31m
C_END		=	\033[0m

################################
############# LIBFT ############
################################

SRC_NAME	+=	ft_atoi.c
SRC_NAME	+=	ft_atoll.c
SRC_NAME	+=	ft_bzero.c
SRC_NAME	+=	ft_calloc.c
SRC_NAME	+=	ft_isalpha.c
SRC_NAME	+=	ft_isascii.c
SRC_NAME	+=	ft_isdigit.c
SRC_NAME	+=	ft_isprint.c
SRC_NAME	+=	ft_itoa.c
SRC_NAME	+=	ft_memccpy.c
SRC_NAME	+=	ft_memchr.c
SRC_NAME	+=	ft_memcmp.c
SRC_NAME	+=	ft_memcpy.c
SRC_NAME	+=	ft_memmove.c
SRC_NAME	+=	ft_memset.c
SRC_NAME	+=	ft_putchar_fd.c
SRC_NAME	+=	ft_putendl_fd.c
SRC_NAME	+=	ft_putnbr_fd.c
SRC_NAME	+=	ft_putstr_fd.c
SRC_NAME	+=	ft_split.c
SRC_NAME	+=	ft_strchr.c
SRC_NAME	+=	ft_strcmp.c
SRC_NAME	+=	ft_strcpy.c
SRC_NAME	+=	ft_strdup.c
SRC_NAME	+=	ft_strjoin.c
SRC_NAME	+=	ft_strlcat.c
SRC_NAME	+=	ft_strlcpy.c
SRC_NAME	+=	ft_strldup.c
SRC_NAME	+=	ft_strlen.c
SRC_NAME	+=	ft_strmapi.c
SRC_NAME	+=	ft_strncmp.c
SRC_NAME	+=	ft_strnstr.c
SRC_NAME	+=	ft_strrchr.c
SRC_NAME	+=	ft_strtrim.c
SRC_NAME	+=	ft_substr.c
SRC_NAME	+=	ft_tolower.c
SRC_NAME	+=	ft_toupper.c

#################################
############## GNL ##############
#################################

SRC_NAME	+=	get_next_line.c

#################################
########### FT_PRINTF ###########
#################################

SRC_NAME	+=	ft_printf.c
SRC_NAME	+=	ft_printf_utils.c
SRC_NAME	+=	ft_printf_utils_2.c
SRC_NAME	+=	ft_printf_check_convert.c
SRC_NAME	+=	ft_printf_get_convert.c
SRC_NAME	+=	ft_printf_do_width_string.c
SRC_NAME	+=	ft_printf_do_width_int.c
SRC_NAME	+=	ft_printf_do_width_ptr.c
SRC_NAME	+=	ft_printf_do_width_int_base.c
SRC_NAME	+=	ft_printf_char.c
SRC_NAME	+=	ft_printf_int.c
SRC_NAME	+=	ft_printf_int_base.c
SRC_NAME	+=	ft_printf_string.c
SRC_NAME	+=	ft_printf_ptr.c
SRC_NAME	+=	ft_printf_modulo.c

#################################
######### MY FUNCTIONS ##########
#################################

SRC_NAME	+=	c_is_alnum.c
SRC_NAME	+=	c_is_str.c
SRC_NAME	+=	print_binary.c
SRC_NAME	+=	where_is_c.c


OBJ_NAME	= $(SRC_NAME:.c=.o)

OBJ_PATH	= ./.obj

SRC_PATH	= ./srcs

HEADER_PATH	= ./include

OBJ		= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
SRC		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo ""
	@echo "$(NAME) [$(C_GREEN)OK$(C_END)]"
	@echo ""

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "$<		[$(C_GREEN)OK$(C_END)]"
	@$(CC) -I$(HEADER_PATH)/ -o $@ $(CFLAGS) $<

clean:
	@$(RM) $(OBJ) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
