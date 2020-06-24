NAME = cub3d_game
FLAGS = -Wall -Werror -Wextra -fsanitize=address -lmlx -framework OpenGL -framework AppKit
HDRS = ./cub.h
SRC = ./cub.h ./engine/error.c
SRC_UTILS = ./utils/ft_atoi.c ./utils/ft_putstr_fd.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c ./utils/ft_bzero.c
SRC_CHECK = ./engine/check/check_filename.c
OBJ = $(SRC:.c=.o) $(SRC_UTILS:.c=.o) $(SRC_CHECK:.c=.o)

%.o:%.c
	@gcc -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[33m Compiling $<\033[0m"

$(NAME): $(OBJ) $(HDRS)
	@gcc -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled cub3D project.\033[0m"

all: log $(NAME)

log:
	@touch log.txt
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Created by log.txt .\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) log.txt
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m log.txt deleted.\033[0m"
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m run_minirt deleted.\033[0m"

re: fclean all

start: all
	@echo "\033[90m[\033[32mStatus\033[90m]\033[33m Start map.cub...\033[0m"
	@./$(NAME) map.cub

.PHONY: all clean fclean re