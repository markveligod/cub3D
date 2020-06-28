NAME = cub3d_game
FLAGS = -Wall -Werror -Wextra -fsanitize=address -lmlx -framework OpenGL -framework AppKit
HDRS = ./cub.h
SRC = ./cub.c ./engine/error.c
SRC_UTILS = ./utils/ft_strncmp.c ./utils/ft_atoi.c ./utils/ft_putstr_fd.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c ./utils/ft_strlcpy.c ./utils/ft_split.c ./utils/ft_bzero.c ./utils/ft_strtrim.c
SRC_CHECK = ./engine/check/check_filename.c ./engine/check/init_check_struct.c ./engine/check/check_line_map.c ./engine/check/check_param_objects.c ./engine/check/match_to_match.c
SRC_GET = ./engine/get_param_objects/get_sprite.c ./engine/get_param_objects/get_param_map.c ./engine/get_param_objects/get_param_objects.c ./engine/get_param_objects/init_param_objects.c ./engine/get_param_objects/sort_param_objects.c
SRC_GAME = ./engine/game/game.c ./engine/game/init_game_struct.c ./engine/game/game_control_keys.c ./engine/game/bitmap.c
SRC_DDA = ./engine/DDA/init_dda_struct.c ./engine/DDA/run_dda.c ./engine/DDA/run_draw.c ./engine/DDA/draw_sprite.c
OBJ = $(SRC:.c=.o) $(SRC_UTILS:.c=.o) $(SRC_CHECK:.c=.o) $(SRC_GET:.c=.o) $(SRC_GAME:.c=.o) $(SRC_DDA:.c=.o)

%.o:%.c
	@gcc -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[33m Compiling $<\033[0m"

$(NAME): $(OBJ) $(HDRS)
	@touch log.txt
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Created by log.txt .\033[0m"
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled cub3D project.\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f cub3d_game log.txt
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m log.txt deleted.\033[0m"
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m cub3d_game deleted.\033[0m"

re: fclean all

start: all
	@echo "\033[90m[\033[32mStatus\033[90m]\033[33m Start map.cub...\033[0m"
	@./$(NAME) map.cub

.PHONY: all clean fclean re