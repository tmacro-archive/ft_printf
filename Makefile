# **************************************************************************** #ME
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 09:30:29 by tmckinno          #+#    #+#              #
#    Updated: 2017/07/15 14:08:29 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libftprintf.a
CC     = gcc
CFLAGS = -Wall -Werror -g #-fsanitize=address
OBJDIR = build
SRCDIR = src
INC    = -I./include/

.PHONY = all clean fclean re

FUNC +=	flags.c \
		util.c \
		memory.c \
		ft_token.c \
		ft_printf.c \
		constant.c \
		render.c \
		f_simple.c \
		formatters.c \
		f_number.c \
		convert.c \
		identity.c \
		string.c \
		f_unsigned.c \
		f_base.c

OBJ = $(FUNC:%.c=$(OBJDIR)/%.o)
SRC = $(addprefix $(SRCDIR)/, $(FUNC))

all: $(NAME) 

$(OBJ): | build

build:
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

test: re
	@$(CC) $(CFLAGS) $(INC) -c main.c
	@$(CC) $(CFLAGS) $(INC) -L. -lftprintf main.o -o printf_test

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean $(NAME)

