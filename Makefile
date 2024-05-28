# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabochko <dabochko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:31:01 by dabochko          #+#    #+#              #
#    Updated: 2024/05/28 14:31:38 by dabochko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

$(CLIENT_NAME): $(PRINTF) $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(CLIENT_NAME)

$(SERVER_NAME): $(PRINTF) $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(SERVER_NAME)

$(PRINTF):
	@make -C printf

%.o: %.c Makefile minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@make -C printf clean

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@make -C printf fclean

re: fclean all

.PHONY: all bonus clean fclean re