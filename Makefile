# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 18:36:00 by jolopez-          #+#    #+#              #
#    Updated: 2023/07/19 17:39:01 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	so_long

SRCS 			= 	srcs/map_tools.c \
				srcs/so_long.c \
				srcs/tools.c

MANDATORY		=	srcs/print.c \
				srcs/movements.c \
				srcs/map_tester.c \
				srcs/mem.c \
				includes/42_gnl/get_next_line.c \
				includes/42_gnl/get_next_line_utils.c

BONUS			=	srcs/bonus/enemies_bonus.c \
				srcs/bonus/enemy_movement_bonus.c \
				srcs/bonus/map_tool_bonus.c \
				srcs/bonus/so_long_bonus.c \
				srcs/bonus/tools_bonus.c

GNL				=	includes/42_gnl/get_next_line.c \
				includes/42_gnl/get_next_line_utils.c

OBJS			=	$(SRCS:%.c=%.o)
MAND_OBJS		=	$(MANDATORY:%.c=%.o)
BONUS_OBJS		=	$(BONUS:%.c=%.o)

INC 			=	-I./includes/so_long.h -I./includes/42_GNL/get_next_line.h -I./includes/42_libft/libft.h
INC_BONUS		=	-I./includes/so_long_bonus.h -I./includes/42_GNL/get_next_line.h -I./includes/42_libft/libft.h

LIBS			=	./includes/42_libft/libft.a ./includes/42_ft_printf/libftprintf.a ./mlx/libmlx.a

MLX_DIR 		=	./mlx

MLX_PATH		=	${MLX_DIR}/libmlx.dylib

CC 				= 	gcc

CFLAGS 			= 	-Wall -Werror -Wextra $(INC) -g3 -fsanitize=address
CFLAGS_BONUS 	= 	-Wall -Werror -Wextra $(INC_BONUS) -g3 -fsanitize=address

MFLAGS			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):		$(MAND_OBJS) $(OBJS)
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd ./includes/42_libft && make
				@echo "$(LIGHT_RED) Creating ft_printf files... $(WHITE)"
				cd ./includes/42_ft_printf && make bonus
#				@echo "$(LIGHT_RED) Creating mlx... $(WHITE)"
#				cd mlx && make
				@echo "$(YELLOW) Creating so_long... $(WHITE)"
				${CC} $(CFLAGS) $(OBJS) $(MAND_OBJS) ${LIBS} ${MFLAGS} -o $(NAME)
				@echo "$(GREEN) Done..."			
			
bonus:			$(MAND_OBJS) $(BONUS_OBJS)
				@echo "$(LIGHT_RED) Creating libft files... $(WHITE)"
				cd ./includes/42_libft && make 
				@echo "$(LIGHT_RED) Creating ft_printf files... $(WHITE)"
				cd ./includes/42_ft_printf && make bonus
				@echo "$(LIGHT_RED) Creating ft_gnl... $(WHITE)"
				${CC} $(CFLAGS) $(BONUS_OBJS) $(MAND_OBJS) ${LIBS} ${MFLAGS} -o $(NAME)
#				@echo "$(LIGHT_RED) Creating mlx... $(WHITE)"
#				cd mlx && make
				@echo "$(YELLOW) Creating so_long with enemies... $(WHITE)"
				${CC} $(CFLAGS_BONUS) $(MAND_OBJS) ${BONUS_OBJS} ${LIBS} ${MFLAGS} -o $(NAME)
				@echo "$(GREEN) Done..."			

clean:		
				@echo "$(LIGHT_RED) Cleaning libft objects... $(WHITE)"
				make clean -C includes/42_libft
				@echo "$(LIGHT_RED) Cleaning ft_printf objects... $(WHITE)"
				make clean -C includes/42_ft_printf
#				@echo "$(LIGHT_RED) Cleaning mlx objects... $(WHITE)"
#				make clean -C mlx
				/bin/rm -rf $(OBJS) $(MAND_OBJS) $(BONUS_OBJS)

fclean: 		clean
				cd ./includes/42_libft && make fclean 
				@echo "$(LIGHT_RED) Cleaning all... $(WHITE)"
				/bin/rm -rf $(NAME) $(BONUS_NAME)

re: 			fclean all

.PHONY: 		all clean fclean re bonus

# COLORS
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
LIGHT_GRAY		= \033[0;37m
DARK_GRAY		= \033[0;90m
LIGHT_RED		= \033[0;91m
WHITE			= \033[0;97m

#SETS
BOLD			= \e[0;1m
UNDERLINED		= \e[0;4m
BLINK			= \e[0;5m