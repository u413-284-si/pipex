# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2022/11/17 12:37:03 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME	= libgnl.a
SRC		= get_next_line_bonus.c get_next_line_utils_bonus.c
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
		@$(MAKE) all -C ../ft_printf
		@cp ../ft_printf/libftprintf.a $@
		@echo "$(YELLOW)Compiling: $^ $(DEF_COLOR)"
		@ar -rcs $@ $^
		@echo "$(GREEN)gnl compiled!$(DEF_COLOR)"

clean: 
		@rm -f $(OBJ)
		@echo "$(BLUE)gnl object files cleaned!$(DEF_COLOR)"

fclean:	clean
		@rm -f $(NAME)
		@echo "$(CYAN)gnl executable & object files cleaned!$(DEF_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re