SRCS = mandatory/so_long.c \
	   mandatory/get_next_line.c \
	   mandatory/get_next_line_utils.c \
	   mandatory/ft_split.c \
	   mandatory/moves.c \
	   mandatory/check_and_get.c \
	   mandatory/check_and_get_part_two.c \
	   mandatory/helper_functions.c \
	   mandatory/helper_functions_part_two.c \
	   mandatory/check_path.c

BONUS_SRCS = bonus/so_long_bonus.c \
			 bonus/get_next_line_bonus.c \
			 bonus/get_next_line_utils_bonus.c \
			 bonus/ft_split_bonus.c \
			 bonus/moves_bonus.c \
			 bonus/init_images_bonus.c \
			 bonus/destroy_images_bonus.c \
			 bonus/check_and_get_bonus.c \
			 bonus/check_and_get_part_two_bonus.c \
			 bonus/helper_functions_bonus.c \
			 bonus/helper_functions_part_two_bonus.c \
			 bonus/helper_functions_part_three_bonus.c \
			 bonus/check_path_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS_NAME = so_long_bonus

all: $(NAME)

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean
