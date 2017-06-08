# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 18:28:41 by sbonnefo          #+#    #+#              #
#    Updated: 2017/06/08 23:02:07 by sbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = src/libft
MLX_PATH = src/mlx

SRC =	$(addprefix $(SRC_PATH)/, main.c \
		ft_errors.c \
		ft_keymenu.c \
		ft_line_al.c \
		ft_menu.c \
		ft_move.c \
		ft_peaks_to_plan.c \
		ft_pers_init.c \
		ft_putkeynbr.c \
		ft_putpeaks.c \
		ft_rotate_x.c \
		ft_rotate_z.c \
		ft_stock_peaks.c \
		ft_parsing.c \
		ft_init_mlx.c)

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

INCLUDES = src/include src/libft src/mlx/mlx.h

LIB = $(LIB_PATH)/libft.a

LIB_MLX = $(MLX_PATH)/libmlx.a

FLAGS = -g -Wall -Wextra -Werror

MLX_INC = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIB) $(LIB_MLX) $(OBJ)
	@gcc $(FLAGS) $(MLX_INC) -o $(NAME) $(LIB) $(LIB_MLX) $(OBJ)
	@echo "$(NAME) \033[30;42mmade\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(LIB_MLX):
	@make -C $(MLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES)
	@gcc $(FLAGS) -o $@ -c $< $(addprefix -I , $(INCLUDES))

debug:
	@gcc -g $(FLAGS) $(MLX_INC) -o $(NAME) $(LIB) $(LIB_MLX) $(OBJ)

norm:
	norminette src/libft src/include
	norminette $(SRC)

clean:
	@rm -Rf $(OBJ)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -Rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@echo "$(NAME) \t\033[30;42m Delete\033[0m\033[0m (make $@ done for $(NAME))"

re: fclean all
