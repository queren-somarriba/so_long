# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsomarri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 18:55:06 by qsomarri          #+#    #+#              #
#    Updated: 2024/09/10 17:03:42 by qsomarri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

CC = @cc

CFLAGS = -Wall -Wextra -Werror -I./includes

RM = @rm -rf

MAKE = @make -C

SRCS_DIR = srcs

SRCS =	$(SRCS_DIR)/map_checkers.c \
	$(SRCS_DIR)/parsing.c \
	$(SRCS_DIR)/error_free_and_close.c \
	$(SRCS_DIR)/so_long.c \
	$(SRCS_DIR)/so_long_utils.c \
	$(SRCS_DIR)/get_and_put_img.c \
	$(SRCS_DIR)/move_player.c \

OBJ_DIR = obj

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS_DIR = bonus

BONUS_SRCS =	$(BONUS_SRCS_DIR)/so_long_bonus.c \
		$(BONUS_SRCS_DIR)/enemy_patrol_bonus.c \
		$(BONUS_SRCS_DIR)/map_checkers_bonus.c \
		$(BONUS_SRCS_DIR)/parsing_bonus.c \
		$(BONUS_SRCS_DIR)/error_free_and_close_bonus.c \
		$(BONUS_SRCS_DIR)/so_long_utils_bonus.c \
		$(BONUS_SRCS_DIR)/so_long_utils_bonus2.c \
		$(BONUS_SRCS_DIR)/get_and_put_img_bonus.c \
		$(BONUS_SRCS_DIR)/move_player_bonus.c \
		$(BONUS_SRCS_DIR)/anim.c \

OBJS_BONUS = $(BONUS_SRCS:$(BONUS_SRCS_DIR)/%:.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(OBJ_DI)/%.o: $(BONUS_SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@

# Cible principale
all: $(NAME)

# Création de l'exécutable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "\033[36m    ______/ \-.   _  "
		@echo "\033[36m .-/     (    o\_//    *~o~o~* SO_LONG Compiled !*~o~o~* "
		@echo "\033[36m  |  ___  \_/\---'   "
		@echo "\033[36m   |_||  |_||        "
		@echo "\033[0;92m * $(NAME) program file was created\033[0m *"

bonus :	$(LIBFT) $(OBJS_BONUS)
	@$(CC) -o $(BONUS_NAME) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		@echo "\033[36m     /\_/\           ___"
		@echo "\033[36m    = o_o =_______    \ \     *~o~o~* BONUS Compiled !*~o~o~* "
		@echo "\033[36m     __^      __(  \.__) )    "
		@echo "\033[36m (@)<_____>__(_____)____/   "
		@echo "\033[0;92m* $(BONUS_NAME) program file was created\033[0m *"


# Construction de la libft
$(LIBFT):
	@$(MAKE) $(LIBFT_PATH) all

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	@$(MAKE) $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

# Nettoyage complet
fclean: clean
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

# Reconstruction complète
re: fclean all

party :	
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re bonus
