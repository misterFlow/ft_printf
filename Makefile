NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS =	\
	ft_printf.c	\
	ft_prct_c_prct.c	\
	ft_prct_d_i_u.c	\
	ft_prct_p.c	\
	ft_prct_s.c	\
	ft_prct_x_X.c	\

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all