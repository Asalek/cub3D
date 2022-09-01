CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
UNAME = $(shell uname -s)

CFILES = main.c \
	./mandatory/tools/tools_00.c \
	./mandatory/tools/tools_01.c \
	./mandatory/parse/get_map.c \
	./mandatory/tools/get_next_line.c \
	./mandatory/parse/map_element_00.c \
	./mandatory/parse/check_map.c \
	./mandatory/parse/check_color.c \
	./mandatory/rayCasting/ray_calculation.c \
	./mandatory/rayCasting/player_direction.c \
	./mandatory/rayCasting/screen.c \
	./mandatory/rayCasting/movement_rotate.c \
	./mandatory/rayCasting/hook_keys.c \
	./mandatory/rayCasting/sprites_display.c


OFILES = $(CFILES:.c=.o)

ifeq ($(UNAME), Darwin)
	MLXFLAGS =  -O3 -lmlx -framework OpenGL -framework AppKit -lz mandatory/minilibx_opengl_20191021/libmlx.a
endif
ifeq ($(UNAME), Linux)
	MLXFLAGS = -lmlx -lXext -lX1
endif

all : $(NAME)

$(NAME) : $(OFILES)
	@${CC} -fsanitize=address $^ -o $@ ${MLXFLAGS}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf ${OFILES}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

bonus : all
