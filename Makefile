SRC_M = src/get_next_line.c src/get_next_line_utils.c

OBJ_M = $(SRC_M:.c=.o)

SRC_B = bonus/src/get_next_line_bonus.c bonus/src/get_next_line_utils_bonus.c

OBJ_B = $(SRC_B:_bonus.c=.o)

NAME = libftgnl.a

AR = ar rcs

CC = cc -Wall -Wextra -Werror

RM = rm -f

%.o: %_bonus.c bonus/include/get_next_line_bonus.h
	$(CC) -c $< -Ibonus/include -o $@

%.o: %.c include/get_next_line.h
	$(CC) -c $< -Iinclude -o $@

all: $(NAME)

$(NAME): $(OBJ_M)
	$(AR) $(NAME) $(OBJ_M)

bonus: $(OBJ_B)
	$(AR) $(NAME) $(OBJ_B)

clean:
	$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all