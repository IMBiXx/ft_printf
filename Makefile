# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 16:36:41 by tpotier           #+#    #+#              #
#    Updated: 2019/04/30 21:55:44 by valecart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FILES = ft_printf io parsing parsing_utils io_csr io_doxb io_utils cast io_f \
		io_k io_other io_p f_utils
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
	gcc -L. -lftprintf -Iincludes -Ilibft main.c -o main


.PHONY: all clean fclean re
-include $(DEPS)
