NAME = Cub3D
FLAGS = -Wall -Wextra -Werror -fsanitize=address -lmlx -framework OpenGL -framework AppKit
HDRS = cub.h
UTILS = ./utils/ft_atoi.c ./utils/ft_bzero.c ./utils/ft_calloc.c ./utils/ft_isspace.c ./utils/ft_putchar_fd.c ./utils/ft_putendl_fd.c \
./utils/ft_putstr_fd.c ./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c ./utils/ft_split.c ./utils/ft_strlcpy.c
ENGINE = ./engine/error.c ./engine/get_next_line.c ./engine/map.c ./engine/param.c ./engine/param_utils.c ./cub.c ./engine/game.c \
./engine/draw.c
OBJS = $(UTILS:.c=.o) $(ENGINE:.c=.o)

%.o:%.c
	@gcc -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[33m Compiling $<\033[0m"

$(NAME) : $(OBJS) $(HDRS)
	@gcc -o $(NAME) $(OBJS) $(FLAGS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Cub3D.\033[0m"

all : $(NAME)

clean :
	@/bin/rm -f $(OBJS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Cub3D deleted.\033[0m"

re : fclean all

start : all
		./Cub3D map.cub

.PHONY: all clean fclean start