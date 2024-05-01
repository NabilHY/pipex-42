CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS_MAN = ./mandatory/srcs/utils.c 
OBJS_MAN = $(SRCS_MAN:%.c=%.o)
LIBR_SRCS = ./libr/libft/ft_isascii.c \
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
	./libr/libft/ft_lstnew.c \
	./libr/libft/ft_lstadd_front.c \
	./libr/libft/ft_lstsize.c \
	./libr/libft/ft_lstlast.c \
	./libr/libft/ft_lstadd_back.c \
	./libr/libft/ft_lstdelone.c \
	./libr/libft/ft_lstclear.c \
	./libr/libft/ft_lstiter.c \
	./libr/libft/ft_lstmap.c \
	./libr/gnl/get_next_line.c \
	./libr/gnl/get_next_line_utils.c
ENTRY = ./mandatory/pipex.c
INCLUDE_MAN = ./mandatory/pipex.h
LIBR_INCLUDE = ./libr/libr.h
LIBR = libr.a
NAME = pipex
BONUS = pipexx

all: $(LIBR) $(NAME)

bonus: $(LIBR) $(NAME)

$(LIBR): $(LIBR_SRCS)
	make -C libr

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I $(INCLUDE_MAN) -c $< -o $@

$(NAME): $(ENTRY) $(OBJS_MAN) $(INCLUDE_MAN) $(LIBR)
	make -C mandatory

$(BONUS): $(OBJS_MAN) $(INCLUDE_MAN) $(LIBR)
	make -C bonus

clean:
	rm -rf $(OBJS_MAN)
	make clean -C libr
	make clean -C mandatory

fclean: clean
	rm -rf $(NAME) $(LIBR)
	make fclean -C libr
	make clean -C mandatory

re: fclean all