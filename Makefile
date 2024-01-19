# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2024/01/19 13:25:07 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES)
RM = rm -rf
INCLUDES = includes/
SRC_DIR = srcs
SRC = ${addprefix ${SRC_DIR}/, push_swap.c parsing.c make_tab.c operators.c rotate.c check_rank.c sorting.c}
OBJ_DIR = obj
OBJ = ${addprefix ${OBJ_DIR}/, ${SRC:.c=.o}}
LIB_DIR = libft
LIB = libft.a

DEFAULT	= \033[0m
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
BWHITE	= \033[1;37m

all: ${NAME}

${NAME}: ${OBJ}
	@make -C ${LIB_DIR} --no-print-directory
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@${CC} ${CFLAGS} ${OBJ} -o $@ ${LIB_DIR}/${LIB}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/${SRC_DIR}
	@${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o $@
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"

clean:
	@make clean -C ${LIB_DIR} --no-print-directory
	@echo "$(RED)! Removing$(DEFAULT) ${OBJ_DIR} files"
	@${RM} ${OBJ_DIR}

fclean: clean
	@make fclean -C ${LIB_DIR} --no-print-directory
	@echo "$(RED)! Removing$(DEFAULT) ${NAME}"
	@${RM} ${NAME}

re: fclean all

cre:
	@clear
	@make re --no-print-directory

norm:
	@norminette $(SRC_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm O.K.$(DEFAULT)"}'
	@norminette $(LIB_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(YELLOW)Norm libft O.K.$(DEFAULT)"}'

x: cre
	@./push_swap "30 60 50 -10 90 80 40 100 20 70"

x2: cre
	@./push_swap "20 30 40 -10 50 90 80 60 70 100 51"

valerie: cre
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "30 60 50 -10 90 80 40 100 20 70"

valentin: cre
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "20 30 40 -10 50 90 80 60 70 100 51"

gx: cre
	@gdb --args ./push_swap "30 60 50 -10 90 80 40 100 20 70"

gx2: cre
	@gdb --args ./push_swap "20 30 40 -10 50 90 80 60 70 100 51"

.PHONY = all clean fclean re norm

check : cre
	@./push_swap "20 30 40 -10 50 90 80 60 70 100 51" | ./checker_linux "20 30 40 -10 50 90 80 60 70 100 51"

new : cre
	@./push_swap "5 4 3 2 1"
