CC = cc
CFLAGS = -Wall -Wextra -Werror -Iget_next_line -Ilibft -g -fsanitize=address
AR = ar
ARFLAGS = -rcs
RM = rm -f
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = $(wildcard *.c) $(wildcard get_next_line/*.c) $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)
TARGET = fdf

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $@ $(OBJ) ./minilibx-linux/libmlx.a $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
