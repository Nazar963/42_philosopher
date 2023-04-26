# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:56:39 by naal-jen          #+#    #+#              #
#    Updated: 2023/04/26 19:15:11 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
INC = -I.
NAME = philo.a
TARGET = philo

CFILES = $(wildcard *.c)

OFILES = $(CFILES:.c=.o)

all: $(NAME) $(TARGET)

$(NAME): $(OFILES)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

$(TARGET): $(CFILES)
	$(CC) -g $(CFLAGS) -pthread $(OFILES) -o $(TARGET)

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft