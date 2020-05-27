# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 14:25:54 by ckakuna           #+#    #+#              #
#    Updated: 2020/05/27 14:25:54 by ckakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Wextra -Werror -fsanitize=address -lmlx -framework OpenGL -framework AppKit
HDRS = cub.h
SRCS =	./cub3d.c ./cub3d.h ./cub3d_utils.c ./error.c ./map.c 
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME) : $(OBJS) $(HDRS)
		@$(MAKE) -C ./libft/
		@gcc -o $(NAME) libft/libft.a $(OBJS) -I $(HDRS) $(FLAGS)
		@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled "libftprintf.a" .\033[0m"

all : $(NAME)

clean :
		@rm -f $(OBJS)
		@$(MAKE) clean -C ./libft
		@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m cub3D cub3D files deleted\033[0m"

fclean : clean
		@rm -f $(NAME)
		@rm -f libft.a
		@$(MAKE) fclean -C ./libft
		@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m cub3D deleted.\033[0m"

re : fclean all

start : all
		./cub3D map.cub

.PHONY: start re fclean clean all
