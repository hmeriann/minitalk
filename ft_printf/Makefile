NAME =	libftprintf.a

SRCS = 		ft_printf.c			ft_print_bigX.c\
			ft_print_c.c		ft_print_di.c\
			ft_print_smallx.c	ft_itoa_upperx.c\
			ft_itoa_smallx_di.c\
			ft_init_tprint.c	ft_parcer.c\
			ft_print_p.c		ft_print_u.c\
			ft_utilities.c

INCLUDE = ft_printf.h
OBJ = $(patsubst %.c,%.o,$(SRCS))

OPTFLAGS = -O2

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB = ar rcs $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	$(LIB)  $?

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -I $(INCLUDE)

bonus : all

clean:
	${RM} $(OBJ) $(OBJ_B)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
