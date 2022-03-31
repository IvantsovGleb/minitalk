cflags = -Wall -Werror -Wextra

rm = rm -rf

SERVER = server

CLIENT = client

src_server = libft/ft_*.c ft_*.c server.c

src_client = libft/ft_*.c ft_*.c client.c


all: $(SERVER) $(CLIENT)

$(ALL): $(SERVER) $(CLIENT)
			$(MAKE) -C libft/
			#$(MAKE) bonus -C libft/

$(SERVER): $(src_server) ft_printf.h
			$(CC) $(cflags) $(src_server) -o $(SERVER)

$(CLIENT): $(src_client) ft_printf.h
			$(CC) $(cflags) $(src_client) -o $(CLIENT)

clean:
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	$(rm) $(SERVER)
	$(rm) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re