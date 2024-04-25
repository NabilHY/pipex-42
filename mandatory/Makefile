CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/utils.c 
OBJS = $(SRCS:%.c=%.o)
ENTRY = ./pipex.c
INCLUDE = ./pipex.h
LIBR = ../libr.a
NAME = ../pipex

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE) $(LIBR)
	$(CC) $(FLAGS) $(ENTRY) -I$(INCLUDE) $(OBJS) $(LIBR) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(LIBR)

re: fclean all