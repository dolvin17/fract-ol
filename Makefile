# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 21:02:51 by dolvin17          #+#    #+#              #
#    Updated: 2023/12/28 12:41:20 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		utils.c \
		fractol.c \
		rendering_fractol.c \
		events.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM_RF = rm -rf
NAME = fractol
MLX_PATH = minilibx_opengl_20191021
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)/$(MLX_NAME)

all: $(MLX) $(NAME)

$(MLX):
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

clean:
	@if [ -e "$(OBJS)" -o -e "$(MLX_PATH)/$(OBJS)" ]; then \
		$(RM_RF) $(OBJS); \
		@make -C $(MLX_PATH) clean; \
	else \
		echo "\033[3;32m....Nothing to clean\033[0m"; \
	fi

fclean:
	@if [ -e "$(NAME)" -o -e "$(MLX)" ]; then \
		$(RM_RF) $(NAME) $(OBJS); \
		make -C $(MLX_PATH) clean; \
		$(RM_RF) $(MLX); \
	else \
		echo "\033[3;31m....Nothing to fclean\033[0m";\
	fi
re: fclean all

.PHONY: clean fclean all re
