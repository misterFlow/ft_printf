# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 11:51:04 by fguy              #+#    #+#              #
#    Updated: 2022/03/03 11:51:08 by fguy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = ./libft.h

SRCS =	\
	ft_nbrlen.c			\
	ft_nbrlen_plus.c	\
	ft_putchar.c		\
	ft_putnbr.c			\
	ft_putnbr_us.c		\
	ft_putstr.c			\
	ft_strlen.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS) 

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.c.o : $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
