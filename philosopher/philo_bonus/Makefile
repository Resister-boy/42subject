NAME = philo_bonus

INCLUDE_DIR = include/
SRC_DIR = srcs/
OBJS_DIR = objs/

CC = gcc
IQUOTES = $(addprefix -iquote,$(INCLUDE_DIR))
CFLAGS = -Wall -Wextra -Werror -MMD -O3 $(IQUOTES)
# -g 
# -fsanitize=address

SRCS = init.c \
	main.c \
	philosophers/forks_manips.c \
	philosophers/philosophing.c \
	philosophers/philosophing2.c \
	philosophers/wait_philosophers.c \
	semaphore.c \
	time/program_start_time.c \
	time/time_diff.c \
	utils/ft_array.c \
	utils/ft_atost.c \
	utils/ft_calloc.c \
	utils/ft_exit.c \
	utils/ft_issize_t.c \
	utils/ft_str.c \
	utils/ft_writenb.c
SRCS := $(addprefix $(SRC_DIR),$(SRCS))
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PONY: all clean fclean re

-include $(DEPS)
