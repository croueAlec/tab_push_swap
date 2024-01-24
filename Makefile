# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2024/01/24 18:37:57 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = push_swap
BONUS = checker

# Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Directories
LIBS_DIR = libs
SRCS_DIR = srcs
INCS_DIR = includes
BONUS_DIR = bonus
OBJS_DIR = objs
LIBFT_DIR = $(LIBS_DIR)/libft

# Files
LIBFT = $(LIBFT_DIR)/libft.a

define LIB :=
	$(LIBFT)
endef
LIB := $(strip $(LIB))

define INCLUDES :=
	$(INCS_DIR)
	$(LIBFT_DIR)
endef
INCLUDES := $(strip $(INCLUDES))

define SRC :=
	apply_cost.c
	check_rank.c
	cost_compare.c
	cost.c
	make_tab.c
	operators.c
	parsing.c
	push_swap.c
	rotate.c
	sorting.c
endef
SRC := $(strip $(SRC))

define BONUS_SRC :=
	$(addprefix $(BONUS_DIR)/, checker_bonus.c \
	make_tab_bonus.c \
	operators_bonus.c \
	parsing_bonus.c \
	push_swap_bonus.c \
	rotate_bonus.c)
endef
BONUS_SRC := $(strip $(BONUS_SRC))

OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
BONUS_OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(BONUS_SRC))

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDES_FLAGS := $(addprefix -I , $(INCLUDES))
LIB_FLAGS = --no-print-directory --silent

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

clean:
	@echo "$(RED)! Removing$(DEFAULT) ${OBJS_DIR} files"
	@${RM} ${OBJS_DIR}

fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)
	@echo "$(RED)! Removing$(DEFAULT) $(BONUS)"
	@$(RM) $(BONUS)

re: fclean all

$(LIBFT):
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

cleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make clean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

fcleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

relib: fcleanlib $(LIBFT)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(BONUS)

cre:
	@clear
	@make re --no-print-directory

norm:
	@norminette $(SRCS_DIR) $(INCS_DIR) $(BONUS_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm O.K.$(DEFAULT)"}'
	@norminette $(LIBFT_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(YELLOW)Norm libft O.K.$(DEFAULT)"}'

valerie: cre
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
