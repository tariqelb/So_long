# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 00:54:22 by tel-bouh          #+#    #+#              #
#    Updated: 2022/03/02 15:57:41 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = ./bonus/so_long

SRCS =  ./so_long.c ./ft_check_map.c ./ft_check_map_2.c ./ft_display_map.c ./ft_event.c \
		./ft_move_player.c ./ft_move_player_2.c ./get_next_line.c \
		./get_next_line_utils.c ./ft_printf.c

SRCS_BONUS = ./bonus/so_long_bonus.c ./bonus/ft_check_map_bonus.c ./bonus/ft_check_map_2_bonus.c ./bonus/ft_display_map_bonus.c \
			 ./bonus/ft_event_bonus.c ./bonus/ft_move_player_bonus.c ./bonus/ft_itoa_bonus.c ./bonus/ft_move_player_2_bonus.c \
			 ./bonus/ft_strjoin_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/ft_printf_bonus.c

#OBJ = ./so_long.o ./ft_check_map.o ./ft_check_map_2.o ./ft_display_map.o ./ft_event.o \
	  ./ft_move_player.o ./ft_move_player_2.o ./get_next_line.o \
	  ./get_next_line_utils.o ./ft_printf.o

#OBJ_BONUS = ./bonus/so_long_bonus.o ./bonus/ft_check_map_bonus.o ./bonus/ft_check_map_2_bonus.o ./bonus/ft_display_map_bonus.o ./bonus/ft_event_bonus.o \
			 ./bonus/ft_move_player_bonus.o ./bonus/ft_move_player_2_bonus.o ./bonus/ft_itoa_bonus.o ./bonus/ft_strjoin_bonus.o \
			 ./bonus/get_next_line_bonus.o ./bonus/get_next_line_utils_bonus.o ./ft_printf_bonus.o

OBJ := $(SRCS:.c=.o)

OBJ_BONUS := $(SRCS_BONUS:.c=.o)

INCLUDES_BONUS = ./bonus

FLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_HEADER = /usr/locale/include

CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -I $(MLX_HEADER) $(MLX_FLAGS) -o $(NAME)

.c.o:
	$(CC) -c $(FALGS) $< -o $@

bonus : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -I $(MLX_HEADER) $(MLX_FLAGS) -o $(NAME_BONUS)

#$(OBJ_BONUS) : $(SRCS_BONUS)
#	$(CC) -c $(FALGS) $(SRCS_BONUS) -I $(INCLUDES_BONUS)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all
