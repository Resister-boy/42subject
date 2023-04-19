NAME = so_long
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
SOURCES = so_long.c \
			./utils/ft_check_utils_1.c \
			./utils/ft_check_utils_2.c \
			./utils/ft_check_utils_3.c \
			./utils/ft_free_utils.c \
			./utils/ft_print_utils.c \
			./lib/ft_lstadd_back.c \
			./lib/ft_lstlast.c \
			./lib/ft_lstsize.c \
			./lib/ft_strdup.c \
			./lib/ft_strlen.c \
			./lib/ft_total_len.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./test/print_map.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

.c.o :
	$(CC)  -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) -o $@ $^
	
clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re