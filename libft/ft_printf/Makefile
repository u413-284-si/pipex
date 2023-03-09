# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2022/11/17 10:36:16 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME	= libftprintf.a
SRC		= ft_printf.c check_flags.c print_tools.c print_char.c \
		print_string.c print_decimal.c print_unsigned.c print_hex.c \
		print_hex_tools.c print_heX.c print_adress.c print_tools_d.c
OBJ 	= $(SRC:%.c=%.o)
CC 		= cc
FLAG 	= -Wall -Werror -Wextra
OPTION 	= -c

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Rules

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling: $^ $(DEF_COLOR)"
	@ar -rcs $@ $^
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean: 
	@rm -f $(OBJ)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@rm -f $(NAME)	
	@echo "$(CYAN)ft_printf executable & object files cleaned!$(DEF_COLOR)"

re:	fclean all

bonus:	all

.PHONY:	all bonus clean fclean re