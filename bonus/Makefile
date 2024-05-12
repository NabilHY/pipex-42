CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/utils_bonus.c \
./srcs/path_bonus.c \
./srcs/list_bonus.c \
./srcs/parsing_bonus.c \
./srcs/pipes_bonus.c
OBJS = $(SRCS:%.c=%.o)
ENTRY = ./pipex_bonus.c
INCLUDE = ./pipex_bonus.h
LIBR = ../libr.a
NAME = ../pipex_bonus
FSANITIZE = -fsanitize=address
LIBR = ../libr.a

all: $(LIBR) $(NAME)

%.o: %.c $(SRCS) $(INCLUDE)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(ENTRY) $(OBJS) $(INCLUDE) $(LIBR)
	$(CC) $(FLAGS) $(ENTRY) -I$(INCLUDE) $(OBJS) $(LIBR) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBR)
re: fclean all