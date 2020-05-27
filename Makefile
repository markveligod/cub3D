# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 14:25:54 by ckakuna           #+#    #+#              #
#    Updated: 2020/05/27 18:39:44 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_cub3d
FLAGS = -Wall -Wextra -Werror -fsanitize=address -lmlx -framework OpenGL -framework AppKit
HDRS = cub3d.h
SRCS =	./cub3d.c ./cub3d_utils.c ./error.c ./map.c 
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -c $<  -o $(<:.c=.o)
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME) : $(OBJS) $(HDRS)
		@$(MAKE) -C ./libft/
		@gcc -o $(NAME) libft/libft.a $(OBJS) -I $(HDRS)
		@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled "run_cub3d" .\033[0m"

all : $(NAME)

clean :
		@rm -f $(OBJS)
		@$(MAKE) clean -C ./libft
		@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m run_cub3d object's files deleted\033[0m"

fclean : clean
		@rm -f $(NAME)
		@rm -f libft.a
		@$(MAKE) fclean -C ./libft
		@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m run_cub3d deleted.\033[0m"

re : fclean all

start : all
		./run_cub3d map.cub

.PHONY: start re fclean clean all
