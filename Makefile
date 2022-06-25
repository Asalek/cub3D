CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
UNAME = $(shell uname -s)

CFILES = ./mandatory/parse/main.c \
	./mandatory/tools/tools_00.c \
	./mandatory/tools/tools_01.c \
	./mandatory/parse/get_map.c \
	./mandatory/tools/get_next_line.c \
	./mandatory/parse/map_element_00.c \
	./mandatory/parse/check_map.c \
	./mandatory/parse/check_color.c

OFILES = $(CFILES:.c=.o)

ifeq ($(UNAME), Darwin)
MLXFLAGS =  -O3 -framework OpenGL -framework AppKit -lz minilibx_opengl_20191021/libmlx.a
# -lmlx
endif
ifeq ($(UNAME), Linux)
	MLXFLAGS = -lm
# -lmlx -lXext -lX1
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
