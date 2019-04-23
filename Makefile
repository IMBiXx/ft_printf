# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 16:36:41 by tpotier           #+#    #+#              #
#    Updated: 2019/04/23 19:28:22 by tpotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FILES = ft_printf io parsing
IFILES = ft_printf.h
NAME = libftprintf.a
IDIR = includes/
SDIR = src/
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
LIBFTINC = $(LIBFTDIR)
CFLAGS = -Wall -Wextra -Werror -I$(IDIR) -I$(LIBFTINC) -MMD -MP

SRCS = $(addprefix $(SDIR), $(addsuffix .c, $(FILES)))
INCS = $(addprefix $(IDIR), $(IFILES))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) libft.a

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar rsc $@ $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make -C $(LIBFTDIR) $@
	rm -f $(OBJS) $(DEPS)
	rm -f main

fclean: clean
	make -C $(LIBFTDIR) $@
	rm -f $(NAME)

re: fclean all

test: all
	gcc -L. -lftprintf -Iincludes main.c -o main


.PHONY: all clean fclean re
-include $(DEPS)