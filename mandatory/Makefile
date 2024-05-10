CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/utils.c \
./srcs/path.c \
./srcs/list.c \
./srcs/parsing.c \
./srcs/pipes.c
OBJS = $(SRCS:%.c=%.o)
ENTRY = ./pipex.c
INCLUDE = ./pipex.h
LIBR = ../libr.a
NAME = ../pipex
FSANITIZE = -fsanitize=address

all: $(NAME)

%.o: %.c $(SRCS) $(INCLUDE)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(ENTRY) $(OBJS) $(INCLUDE) $(LIBR)
	$(CC) $(FLAGS) $(ENTRY) -I$(INCLUDE) $(OBJS) $(LIBR) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBR)
re: fclean all