CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
UNAME = $(shell uname -s)

CFILES = main.c \
		tools_00.c \
		tools_01.c \
		get_map.c \
		get_next_line.c \
		map_element_00.c \
		check_map.c \
		check_color.c

OFILES = $(CFILES:.c=.o)

ifeq ($(UNAME), Darwin)
MLXFLAGS =  -O3 -lmlx -framework OpenGL -framework AppKit -lz minilibx_opengl_20191021/libmlx.a
endif
ifeq ($(UNAME), Linux)
	MLXFLAGS = -lmlx -lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OFILES)
	@${CC} $^ -o $@ ${MLXFLAGS}

$(SRC)/%.o: $(SRC)/%.c include/%.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf ${OFILES}

fclean : clean
	@rm ${NAME}

re : fclean all

bonus : all
