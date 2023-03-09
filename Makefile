# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2023/03/09 11:30:26 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Constants

NAME		= pipex
BONUSNAME	= super_pipex

CFLAGS 		= -Wall -Wextra -Werror
CPPFLAGS	= -I/usr/include -I./inc					# search in directories for included Makefiles
LDFLAGS		= -L./libft -L/usr/lib						# search for libraries in libft and /usr/lib
LDLIBS		= -lft 										# link libraries: libft
OPTION 		= -c -O3									# -c generates object files, -O3 adds compile time, but reduces execution time and code size 					
DEBUG		= -g
CC 			= cc

INCDIR		= ./inc/
INCLIST		= pipex.h error.h 
INCLIST_B	= pipex.h error.h
INC			= $(addprefix ${INCDIR}, ${INCLIST})
INC_B		= $(addprefix ${INCDIR}, ${INCLIST_B})

SRCDIR		= ./src/
SRCLIST		= error.c main.c 
SRCLIST_B	= error.c main_bonus.c 
SRC			= $(addprefix ${SRCDIR}, ${SRCLIST})
SRC_B		= $(addprefix ${SRCDIR}, ${SRCLIST_B})

OBJDIR		= ./obj/
OBJLIST		= $(SRCLIST:%.c=%.o)
OBJLIST_B	= $(SRCLIST_B:%.c=%.o)
OBJ			= $(addprefix ${OBJDIR}, ${OBJLIST})
OBJ_B		= $(addprefix ${OBJDIR}, ${OBJLIST_B})


#Colours

DEF_COLOUR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Rules

all:			$(NAME)

bonus:			$(BONUSNAME)

$(NAME):		$(OBJDIR) $(OBJ)
				@echo "\n$(YELLOW)Compiling: $@ $(DEF_COLOUR)"
				@$(MAKE) all -C ./libft
				@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) -o $@
				@echo "\n$(GREEN)$@ compiled!$(DEF_COLOUR)"

$(BONUSNAME):	$(OBJDIR) $(OBJ_B)
				@echo "\n$(YELLOW)Compiling: $@ $(DEF_COLOUR)"
				@$(MAKE) all -C ./libft
				@$(CC) $(OBJ_B) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) -o $@
				@echo "\n$(GREEN)$@ compiled!$(DEF_COLOUR)"

$(OBJDIR)%.o:	$(SRCDIR)%.c $(INC)
				@$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTION) $(DEBUG) $< -o $@

$(OBJDIR):
				@mkdir $@

clean:
				@$(MAKE) clean -C ./libft
				@rm -rf $(OBJDIR)
				@echo "$(BLUE)object files cleaned!$(DEF_COLOUR)"
fclean: 		clean
				@$(MAKE) fclean -C ./libft
				@rm -f $(NAME)
				@rm -f $(BONUSNAME)
				@echo "$(CYAN)executable & object files cleaned!$(DEF_COLOUR)"

re: 			fclean all

valgr:			
				@valgrind --leak-check=full\
						--show-leak-kinds=all\
						--log-file=valgrind-out.txt\
						./pipex infile "ls -l" "wc -l" outfile
				@less ./valgrind-out.txt

valgr_b:			
				@valgrind --leak-check=full\
						--show-leak-kinds=all\
						--log-file=valgrind-out.txt\
						./super_pipex infile "ls -l" "wc -l" outfile
				@less ./valgrind-out.txt

.PHONY: 		all clean fclean re
