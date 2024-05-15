CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS_MAN = ./mandatory/srcs/utils.c \
./mandatory/srcs/list.c \
./mandatory/srcs/path.c \
./mandatory/srcs/parsing.c \
./mandatory/srcs/pipes.c
SRCS_BON = ./bonus/srcs/list_bonus.c \
./bonus/srcs/parsing_bonus.c \
./bonus/srcs/path_bonus.c \
./bonus/srcs/pipes_bonus.c \
./bonus/srcs/utils_bonus.c
SRCS_LIBR = ./libr/libft/ft_isascii.c \
	./libr/libft/ft_isalpha.c \
	./libr/libft/ft_isdigit.c \
	./libr/libft/ft_isprint.c \
	./libr/libft/ft_isalnum.c \
	./libr/libft/ft_strlen.c \
	./libr/libft/ft_memset.c \
	./libr/libft/ft_bzero.c \
	./libr/libft/ft_memcpy.c \
	./libr/libft/ft_memmove.c \
	./libr/libft/ft_strlcpy.c \
	./libr/libft/ft_strlcat.c \
	./libr/libft/ft_toupper.c \
	./libr/libft/ft_tolower.c \
	./libr/libft/ft_strchr.c \
	./libr/libft/ft_strrchr.c \
	./libr/libft/ft_strncmp.c \
	./libr/libft/ft_memchr.c \
	./libr/libft/ft_memcmp.c \
	./libr/libft/ft_strnstr.c \
	./libr/libft/ft_atoi.c \
	./libr/libft/ft_itoa.c \
	./libr/libft/ft_calloc.c \
	./libr/libft/ft_strdup.c \
	./libr/libft/ft_substr.c \
	./libr/libft/ft_strjoin.c \
	./libr/libft/ft_strtrim.c \
	./libr/libft/ft_split.c \
	./libr/libft/ft_striteri.c \
	./libr/libft/ft_strmapi.c \
	./libr/libft/ft_putchar_fd.c \
	./libr/libft/ft_putstr_fd.c \
	./libr/libft/ft_putnbr_fd.c \
	./libr/libft/ft_putendl_fd.c \
	./libr/gnl/get_next_line.c \
	./libr/gnl/get_next_line_utils.c
OBJS_MAN = $(SRCS_MAN:%.c=%.o)
OBJS_BON = $(SRCS_BON:%.c=%.o)
OBJS_LIBR = $(SRCS_LIBR:%.c=%.o)
ENTRY = ./mandatory/pipex.c
ENTRY_BON = ./bonus/pipex_bonus.c
INCLUDE_MAN = ./mandatory/pipex.h
INCLUDE_BON = ./bonus/pipex_bonus.h
LIBR_INCLUDE = ./libr/libr.h
LIBR = libr.a
NAME = pipex
BONUS = pipex_bonus

all: $(LIBR) $(NAME)

bonus: $(LIBR) $(BONUS)

$(LIBR): $(SRCS_LIBR) $(OBJS_LIBR)
	@echo "Compiling libr ..."
	@ar rcs $(LIBR) $(OBJS_LIBR)
	@echo "libr.a Compiled"

%.o: %.c $(INCLUDE_MAN) $(INCLUDE_BON)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -I$(INCLUDE) -I$(MLX_INCLUDE) -c $< -o $@

$(NAME): $(ENTRY) $(OBJS_MAN) $(INCLUDE_MAN) $(LIBR)
	@echo "Compiling Mandatory part dependencies..."
	@$(CC) $(FLAGS) $(ENTRY) -I$(INCLUDE_MAN) $(OBJS_MAN) $(LIBR) -o $(NAME)
	@echo "Program Compiled Successefully !"

$(BONUS): $(ENTRY_BON) $(OBJS_BON) $(INCLUDE_BON) $(LIBR)
	@echo "Compiling Bonus part dependencies..."
	@$(CC) $(FLAGS) $(ENTRY_BON) -I$(INCLUDE_BON) $(OBJS_BON) $(LIBR) -o $(BONUS)
	@echo "Bonus Part Compiled Successefully !"

clean:
	@echo "Deleting Object Files ..."
	@rm -rf $(OBJS_MAN) $(OBJS_BON) $(OBJS_LIBR)
	@echo "Deleted!"

fclean: clean
	@echo "Removing Execu files ..."
	@rm -rf $(NAME) $(LIBR) $(BONUS)
	@echo "Deleted!"
re: fclean all