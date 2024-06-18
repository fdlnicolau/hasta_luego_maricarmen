NAME        =   so_long
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror -MMD -g3
RM          =   rm -rf

SRC_DIR     =   src
OBJ_DIR     =   obj
LIBFT_SRC   =   libft
MLX_SRC     =   MLX42

SRC_FILES   =   main.c \
				free.c \
				check_map.c \
				utils.c \
				parsing.c\
				init_game.c\
				key_hook.c\
				parsing2.c


OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_SRC)
	cmake --build $(MLX_SRC)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_SRC)/libmlx42.a libft/libft.a -lglfw -ldl -L/usr/lib/x86_64-linux-gnu/
	@echo So_long compilado

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_SRC) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_SRC) fclean
	cmake --build $(MLX_SRC) --target clean
	@echo Todo limpio

re: fclean all

.PHONY: all clean fclean re