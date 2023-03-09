# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:37:52 by sqiu              #+#    #+#              #
#    Updated: 2022/11/17 12:37:44 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libft.a
INC			= libft.h
SRC			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCB 		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
OBJ			= $(SRC:%.c=%.o) 
OBJB 		= $(SRCB:%.c=%.o)
CFLAGS 		= -Wall -Wextra -Werror
#LDFLAGS		= -L/gnl
#LDLIBS		= -lgnl
OPTION 		= -c
CC 			= cc

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

$(NAME): $(OBJ) $(OBJB)
		@$(MAKE) all -C ./gnl
		@cp gnl/libgnl.a $@
		@echo "$(YELLOW)Compiling: $^ $(DEF_COLOR)"
		@ar rcs $@ $^
		@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

#%.o:	 %.c 
#		@$(CC) $(CFLAGS) $(OPTION) $(LDFLAGS) $< $(LDLIBS) -o $@

clean:
		@$(MAKE) clean -C ./ft_printf
		@$(MAKE) clean -C ./gnl
		@rm -f $(OBJ) $(OBJB)
		@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"
fclean: clean
		@$(MAKE) fclean -C ./ft_printf
		@$(MAKE) fclean -C ./gnl
		@rm -f $(NAME)
		@echo "$(CYAN)ft_printf executable & object files cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
