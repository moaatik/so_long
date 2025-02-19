SRCS = so_long.c get_next_line.c get_next_line_utils.c ft_split.c moves.c check_and_get.c check_and_get_part_two.c helper_functions.c helper_functions_part_two.c check_path.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
