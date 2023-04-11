# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:56:39 by naal-jen          #+#    #+#              #
#    Updated: 2023/04/08 15:59:34 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
INC = -I.
NAME = philo.a

MAN = main utils

MANFC = $(addsuffix .c, $(MAN))

MANO = $(MANFC:.c=.o)

all: $(NAME)

$(NAME): $(MANO)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	@rm -f $(MANO) $(BONO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re