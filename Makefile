NAME = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c utils.c
SRCS_C = client.c utils.c ft_atoi.c
INC = minitalk.h
OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
RM = rm
RMFLAGS = -f


all: $(NAME) ${NAME_CLIENT}

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_C)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) ${NAME_CLIENT}

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I ${INC} -o $@ $^

$(NAME_CLIENT): $(OBJS_C)
	$(CC) $(CFLAGS) -I ${INC} -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re