NAME = libftprintf.a

SRC = 	includes/ft_printf.c	\
		includes/ft_put.c		\
		includes/ft_itoa.c		\
		includes/ft_itoa_base.c	\
		includes/ft_atoi.c		\
		includes/ft_strlen.c	\
		includes/ft_space.c		\

DOT = 	ft_printf.o				\
		ft_put.o				\
		ft_itoa.o				\
		ft_itoa_base.o			\
		ft_atoi.o				\
		ft_strlen.o				\
		ft_space.o				\

all:	$(NAME)
$(NAME):
	@gcc -c $(SRC)    # NEED FLAGS
	@ar rc $(NAME) $(DOT)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(DOT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
