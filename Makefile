CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm -f
#LDFLAGS = -Lminilibx-linux -l:libmlx.a -lXext -lX11

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = fdf.a

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./minilibx-linux
	$(AR) $(ARFLAGS) $@ $(OBJ) ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re