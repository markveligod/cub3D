NAME = run_minirt
FLAGS = -Wall -Werror -Wextra -fsanitize=address -lmlx -framework OpenGL -framework AppKit
CC = gcc 
HDRS = ./minirt.h
SRC_UTILS = ./utils/ft_atof.c ./utils/ft_atoi.c ./utils/ft_putstr_fd.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/get_next_line.c \
./utils/ft_bzero.c
SRC_ENGINE = ./engine/error.c ./engine/get_param_obj.c ./engine/init_object/init_ambient.c ./engine/init_object/init_camera.c ./engine/init_object/init_cylinder.c \
./engine/init_object/init_display.c ./engine/init_object/init_light.c ./engine/init_object/init_plane.c ./engine/init_object/init_sphere.c ./engine/init_object/init_square.c \
./engine/init_object/init_triangle.c ./engine/get_utils.c ./engine/check_utils.c
SRC = ./minirt.c
SRC_MATH = ./engine/math/ray_tracing.c
OBJ = $(SRC_MATH:.c=.o) $(SRC_UTILS:.c=.o) $(SRC_ENGINE:.c=.o) $(SRC:.c=.o)

%.o:%.c
	@$(CC) -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[33m Compiling $<\033[0m"

$(NAME): $(OBJ) $(HDRS)
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled miniRT project.\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m run_minirt deleted.\033[0m"

re: fclean all

start: all
	@/bin/rm -f log.txt
	@echo "\033[90m[\033[91mWarning\033[90m]\033[31m log.txt deleted\033[0m"
	./run_minirt scene.rt

.PHONY: all clean fclean re bonus