# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:56:39 by naal-jen          #+#    #+#              #
#    Updated: 2023/04/25 20:07:57 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
INC = -I.
NAME = philo.a
LIBFTA = libft/libft.a
TARGET = philo

CFILES = $(wildcard *.c)

OFILES = $(CFILES:.c=.o)

all: libft $(NAME) $(TARGET)

libft:
	@$(MAKE) -C libft

$(NAME): $(OFILES)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

$(TARGET): $(CFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(TARGET)

clean:
	@rm -f $(OFILES)
	$(MAKE) -C libft fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft