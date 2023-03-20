# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/03/20 15:44:05 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME	= libgnl.a
SRC		= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ 	= $(SRC:%.c=%.o)
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra
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
		@$(MAKE) all --no-print-directory -C ../ft_printf
		@cp ../ft_printf/libftprintf.a $@
		@echo "$(YELLOW)Compiling: $^ $(DEF_COLOR)"
		@ar -rcs $@ $^
		@echo "$(GREEN)gnl compiled!$(DEF_COLOR)\n"

%.o:	 %.c 
		@$(CC) $(CFLAGS) $(OPTION) $< -o $@

clean: 
		@rm -f $(OBJ)
		@echo "$(BLUE)gnl object files cleaned!$(DEF_COLOR)"

fclean:
		@rm -f $(NAME)
		@echo "$(CYAN)gnl executable cleaned!$(DEF_COLOR)"

re:	clean fclean all

.PHONY:	all clean fclean re