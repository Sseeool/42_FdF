CC = cc
CFLAGS = -Wall -Wextra -Werror -Iget_next_line -Ilibft -fsanitize=address -g
AR = ar
ARFLAGS = -rcs
RM = rm -f
LDFLAGS = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

SRC = $(wildcard *.c) $(wildcard get_next_line/*.c) $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)
TARGET = fdf

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./minilibx_macos
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
