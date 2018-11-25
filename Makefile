SRCS = main.c \
	   parser.c \
	   matrix.c \
	   algo.c \
	   string_gen.c
OBJS = $(SRCS:.c=.o)
export CFLAGS += -Wall -Wextra -Werror
INCLUDES = -Iincludes/ -Ilibft/includes
NAME = fillit

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	gcc -Llibft -lft $^ -o $@

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $^ -o $@

libft/libft.a:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft libclean
	rm -f $(NAME)

re: fclean
	make all
