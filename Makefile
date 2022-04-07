cflags		= -Wall -Werror -Wextra

rm			= rm -rf

SERVER		= server

CLIENT		= client

src_server	= ft_*.c server.c

src_client	= ft_*.c parse.c client.c


all: $(SERVER) $(CLIENT)

libft/libft.a: $(wildcard libft/*.o)
			$(MAKE) -C libft/
			$(MAKE) bonus -C libft/

$(SERVER): libft/libft.a $(src_server) ft_printf.h
			$(CC) $(cflags) libft/libft.a $(src_server) -o $(SERVER)

$(CLIENT): libft/libft.a $(src_client) ft_printf.h parse.h
			$(CC) $(cflags) libft/libft.a $(src_client) -o $(CLIENT)

clean:
			$(MAKE) clean -C libft/

fclean: clean
			$(MAKE) fclean -C libft/
			$(rm) $(SERVER)
			$(rm) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re