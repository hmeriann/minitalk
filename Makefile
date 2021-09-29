NAME1	= client
NAME2	= server
NAME3	= client_bonus
NAME4	= server_bonus

FLAGS	= -Wall -Wextra -Werror

LIBFT	= libft/libft.a

PRINTF	= ft_printf/libftprintf.a

HEAD	= minitalk.h

all :
	make -C libft
	make -C ft_printf
	gcc $(FLAGS) client.c $(LIBFT) $(PRINTF) -o $(NAME1)
	gcc $(FLAGS) server.c $(LIBFT) $(PRINTF) -o $(NAME2)

bonus :
	make -C libft
	make -C ft_printf
	gcc $(FLAGS) client_bonus.c $(LIBFT) $(PRINTF) -o $(NAME3)
	gcc $(FLAGS) server_bonus.c $(LIBFT) $(PRINTF) -o $(NAME4)

clean :
	make clean -C libft
	make clean -C ft_printf
	rm -rf client.o server.o client_bonus.o server_bonus.o

fclean : clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re : fclean all

.PHONY: all clean fclean re bonus
