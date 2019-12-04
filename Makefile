# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:42:47 by edillenb          #+#    #+#              #
#    Updated: 2019/10/28 10:27:56 by thallot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = thallot.filler

CFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = libft/libft.a

OBJDIR = obj
SRCDIR = src

SC = $(addsuffix .c, filler parsing tetri free map place)

SRCS = $(addprefix $(SRCDIR)/, $(SC))
OBJS = $(addprefix $(OBJDIR)/, $(SC:.c=.o))
INCLS = $(addprefix ./include/, $(addsuffix .h, filler))

GREEN = \033[01;32m
BLUE = \033[01;34m
_BLUE=$ \x1b[36m
GREY=$ \x1b[33m
RED = \033[01;31m
YELLOW = \033[01;33m
MAGENTA = \033[35m
BLACK = \033[30m
NOCOLOR = \033[0m
WHITE=$ \x1b[37m

BOLD= \033[1m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(INCLS) Makefile
	@echo "$(BOLD)$(GREY)~~~~~~~~~~~~ Generation ~~~~~~~~~~~~"
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[OK] $(GREY)Tous les objets de $(WHITE)$(NAME) $(_BLUE)sont generes !\r"
	@echo "$(GREEN)[OK] $(GREY)Compilation de $(WHITE)$(NAME)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@mkdir -p obj
	  @$(CC) $(CFLAGS) -c -o $@ $< && printf "$(GREEN)[OK] $(GREY)Generation de $(WHITE)%-50s\r" "$@" || \
		(echo "$(_RED)[ERREUR]$(_GRAY) Une est erreur est survenue sur $(WHITE)$<$(RED), $(WHITE)$(NAME)$(RED) non compilé(e)\n" && exit 1)

$(LIBFT): FORCE
	@echo "$(BOLD)$(_BLUE)~~~~~~~~~~~~ Library ~~~~~~~~~~~~~~~"
	@make -C libft/
	@echo "$(NOCOLOR)"

FORCE:

clean:
	@echo "$(BOLD)$(RED)~~~~~~~~~~~~ Delete ~~~~~~~~~~~~~~~~"
	@echo "$(GREEN)[OK]$(RED) Supression des objets de $(WHITE)$(NAME)"
	@echo "$(GREEN)[OK]$(RED) Supression des objets de $(WHITE)libft.a"
	@make clean -C libft
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(GREEN)[OK]$(RED) Supression de $(WHITE)$(NAME)"
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft/libft.a draw
