CC = cc
CFLAGS = -Wall -Wextra -Werror -Iget_next_line
RM = rm -f
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = ./srcs/bresenham.c \
		./srcs/center.c \
		./srcs/close.c \
		./srcs/error.c \
		./srcs/fdf.c \
		./srcs/make_map.c \
		./srcs/read_map.c \
		./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c
OBJ = $(SRC:.c=.o)
TARGET = fdf

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./minilibx-linux
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $(OBJ) ./minilibx-linux/libmlx.a ./libft/libft.a $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./minilibx-linux/libmlx.a
	make -C ./libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./libft fclean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
