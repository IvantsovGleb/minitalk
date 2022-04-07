cflags	= -Wall -Wextra -Werror

rm		= rm -rf

name	= libft.a

header	= libft.h

srcm	= ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
			ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
			ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
			ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c	ft_toupper.c ft_isalpha.c \
			ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_utoa.c

objm	= $(srcm:.c=.o)

srcb	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c

objb	= $(srcb:.c=.o)


all: $(name)

$(name): $(if $(findstring bonus, $(MAKECMDGOALS)), $(objb), $(objm))
	ar -crs $(name) $?

$(objm): %.o: %.c $(header)
	$(CC) $(cflags) -c $< -o $@

$(objb): %.o: %.c $(header)
	$(CC) $(cflags) -c $< -o $@

bonus: $(name)

clean:
	$(rm) *.o

fclean: clean
	$(rm) $(name)

re: fclean all
		
.PHONY: all clean fclean re bonus
