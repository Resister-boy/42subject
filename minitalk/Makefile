CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = client server
RM = fm
RMFLAGS = -rf

CLIENT_SRCS = client.c client_util.c 
SERVER_SRCS = server.c server_util.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

FT_PRINTF_PATH = ft_printf
FT_PRINTF = libftprintf.a

LIBFT_PATH = libft
LIBFT = libft.a

all : $(NAME)

client: $(CLIENT_OBJS) $(FT_PRINTF_PATH)/*.c $(LIBFT_PATH)/*.c
			make -C $(FT_PRINTF_PATH) all
			make -C $(LIBFT_PATH) all
			$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) -L ./ft_printf -lftprintf ./libft -lft

server: $(SERVER_OBJS) $(FT_PRINTF_PATH)/*.c $(LIBFT_PATH)/*.c
			make -C $(FT_PRINTF_PATH) all
			make -C $(LIBFT_PATH) all
			$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) -L ./ft_printf -lftprintf ./libft -lft

client.o: $(CLIENT_OBJS)
		$(CC) $(CFLAGS) -c $^

server.o: $(SERVER_SRCS)
		$(CC) $(CFLAGS) -c $^

clean: 
	make -C $(FT_PRINTF_PATH) clean
	make -C $(LIBFT_PATH) clean
	$(RM) $(RMFLAGS) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	make -C $(FT_PRINTF_PATH) fclean
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
