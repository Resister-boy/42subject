NAME = pipex
CC = gcc 
CFLAGS = -o -c
RM = rm
RMFLAGS = -rf 
SOURCES = pipex.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJECTS)
	rm -rf $(BONUS_OBJECTS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean
	make

.PHONY: all bonus clean fclean re