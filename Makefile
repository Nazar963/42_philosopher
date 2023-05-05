# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:56:39 by naal-jen          #+#    #+#              #
#    Updated: 2023/05/05 11:40:30 by naal-jen         ###   ########.fr        #
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
	@echo "\033[35m  ̿ ̿ ̿'̿'\̵͇̿̿\з=(•_•)=ε/̵͇̿̿/'̿'̿ ̿  compiling ...̿ ̿ ̿'̿'\̵͇̿̿\з=(•_•)=ε/̵͇̿̿/'̿'̿ ̿\033[0m"
	@$(AR) $(ARF) $@ $^
	@echo "\033[36mcompilied ʕ•ᴥ•ʔ\033[0m"

%.o: %.c
	@$(CC) -g -c $(CFLAGS) $(INC) $< -o $@

$(TARGET): $(CFILES)
	@$(CC) -g $(CFLAGS) -pthread $(OFILES) -o $(TARGET)

clean:
	@rm -f $(OFILES)

fclean: clean
	@echo "\033[35mclean clean clean\033[0m"
	@rm -f philo
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft