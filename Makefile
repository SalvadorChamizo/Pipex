NAME = pipex
NAME_BNS = pipex_bonus
CC = gcc
FLAGS = -g -Wall -Werror -Wextra -Iinclude
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

FILES =	pipex \
		check_arguments \
		free_memory \
		pipex_utils \

BNS_FILES = pipex_bns \
		check_arguments_bns \
		free_memory_bns \
		here_doc_funcs \
		open_fd_bns \
		pipex_utils_bns \

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
BNS_SRC_DIR = ./bns/
BNS_SRCS = $(addprefix $(BNS_SRC_DIR), $(addsuffix .c, $(BNS_FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
BNS_OBJ_DIR = ./bns/
BNS_OBJS = $(addprefix $(BNS_OBJ_DIR), $(addsuffix .o, $(BNS_FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BNS)

$(NAME_BNS): $(LIBFT) $(BNS_OBJS) $(OBJS)
	@$(CC) $(FLAGS) $(BNS_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean: 
	@rm -f $(OBJS) $(BNS_OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BNS)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY = all clean fclean re libft bonus