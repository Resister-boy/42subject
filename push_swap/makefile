NAME = push_swap
CC = gcc
CFLAGS = -o
RM = RD
RMFLAGS = -Force
SOURCES = push_swap.c \
			./utils/command_utils.c \
			./utils/arg_utils.c \
			./utils/stack_utils.c \
			./utils/sort_utils.c \
			./utils/sort_type_a_utils.c \
			./utils/sort_type_b_utils.c \
			./utils/print_utils.c \
			./utils/etc_utils.c \
			./utils/push_utils.c \
			./lib/ft_atoi.c \
			./lib/ft_split.c \
			./lib/ft_strlen.c \
			./lib/ft_strlcpy.c \
			./lib/ft_lstadd_back.c \
			./lib/ft_lstlast.c \
			./lib/ft_lstnew.c \
			./lib/ft_lstsize.c \
			./command/ft_push.c \
			./command/ft_swap.c \
			./command/ft_rotate.c \
			./command/ft_reverse_rotate.c \
			test_utils.c

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(NAME) $(SOURCES)

.PHONY: all clean fclean