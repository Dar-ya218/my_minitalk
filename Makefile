CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRCS = client.c ft_atoi.c
SERVER_SRCS = server.c

OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)
OBJS_SERVER = $(SERVER_SRCS:.c=.o)

PRINTF = printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)