NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset \
        ft_bzero \
        ft_memcpy \
        ft_memmove \
        ft_memchr \
        ft_memcmp \
        ft_strlen \
        ft_strlcpy \
        ft_strlcat \
        ft_strchr \
        ft_strrchr \
        ft_strnstr \
        ft_strcmp \
        ft_strncmp \
        ft_atoi \
        ft_isalpha \
        ft_isdigit \
        ft_isalnum \
        ft_isascii \
        ft_isprint \
        ft_toupper \
        ft_tolower \
        ft_calloc \
        ft_strdup \
        ft_substr \
        ft_strjoin \
        ft_strtrim \
        ft_split \
        ft_itoa \
        ft_strmapi \
        ft_striteri \
        ft_putchar_fd \
        ft_putstr_fd \
        ft_putendl_fd \
        ft_putnbr_fd \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \
		ft_printf \
		ft_print_char \
		ft_print_str \
		ft_print_nbr \
		ft_print_ptr \
		ft_print_ptrhex \
		ft_print_unsig \
		ft_print_hex \
		ft_print_hexup \
		get_next_line \
		get_next_line_utils \

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $@ $^

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re