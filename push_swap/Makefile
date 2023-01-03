# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 15:47:55 by gda-cruz          #+#    #+#              #
#    Updated: 2023/01/03 00:34:09 by gda_cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[1;32m
LIGHT_GREEN	=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

NAME 		=	push_swap
B_NAME 		=	checker

LIBFT_DIR	=	libft

SRC			=	srcs/mandatory/main.c \
				srcs/mandatory/algo.c \
				srcs/mandatory/input.c \
				srcs/mandatory/operations.c \
				srcs/mandatory/free.c \
				srcs/mandatory/stack_utils.c \
				srcs/mandatory/stack_utils2.c \
				srcs/mandatory/stack_utils3.c \

B_SRC		=	srcs/bonus/main_bonus.c \
				srcs/bonus/error_bonus.c \
				srcs/bonus/operations_bonus.c \
				srcs/mandatory/input.c \
				srcs/mandatory/operations.c \
				srcs/mandatory/free.c \
				srcs/mandatory/stack_utils.c \
				srcs/mandatory/stack_utils2.c \

OBJ			=	$(SRC:srcs/mandatory/%.c=$(OBJ_DIR)/%.o)
B_OBJ		=	$(B_SRC:srcs/bonus/%.c=$(B_OBJ_DIR)/%.o)
INC_DIR		=	inc
BUILD_DIR	=	./build
BIN_DIR		=	$(BUILD_DIR)/bin
OBJ_DIR		=	$(BUILD_DIR)/objects
B_OBJ_DIR	=	$(BUILD_DIR)/b_objects
BIN			=	$(BIN_DIR)/$(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -I$(INC_DIR) -Ilibft/inc # -fsanitize=address

all: $(NAME)

$(NAME): $(BIN)

$(BIN):	$(OBJ) | $(BIN_DIR)
	@echo ""
	@echo "$(YELLOW)  Preparing push_swap...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(LIGHT_GREEN)  Libft successfully compiled.$(RESET)"
	@$(CC) $(CFLAGS) -o $(@) $(^) -L$(LIBFT_DIR) -lft
	@echo "$(LIGHT_GREEN)  push_swap successfully compiled.$(RESET)"
	@echo "$(GREEN)\n$(RESET)"

$(OBJ_DIR)/%.o:	srcs/mandatory/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $(^) -o $(@)

.SILENT = $(OBJ)
.SILENT = $(B_OBJ)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(B_OBJ_DIR) $(BIN_DIR)

bonus: $(B_OBJ) | $(BIN_DIR)
	@echo ""
	@echo "$(YELLOW)  Preparing checker...$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(LIGHT_GREEN)  Libft successfully compiled.$(RESET)"
	@$(CC) $(CFLAGS) -o $(B_NAME) $(^) -L$(LIBFT_DIR) -lft
	@echo "$(LIGHT_GREEN)  checker successfully compiled.\n$(RESET)"
	@mv $(B_NAME) build/bin

$(B_OBJ_DIR)/%.o:	srcs/bonus/%.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $(^) -o $(@)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(B_OBJ_DIR)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -rf build
	@echo "$(RED)  All push_swap files removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus