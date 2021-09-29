# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 17:14:40 by hmeriann          #+#    #+#              #
#    Updated: 2021/09/26 16:52:55 by hmeriann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =		ft_memset.c		ft_bzero.c		ft_memcpy.c\
			ft_memccpy.c	ft_memmove.c	ft_memchr.c\
			ft_memcmp.c		ft_strlen1.c	ft_strlcpy.c\
			ft_strlcat.c	ft_strchr.c		ft_strrchr.c\
			ft_strnstr.c	ft_strncmp.c	ft_atoi1.c\
			ft_isalpha.c	ft_isdigit1.c	ft_isalnum.c\
			ft_isascii.c	ft_isprint.c	ft_toupper.c\
			ft_tolower.c	ft_calloc.c		ft_strdup.c\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c\
			ft_split.c		ft_itoa1.c		ft_strmapi.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd1.c\

LIST_B =	ft_lstnew.c		ft_lstadd_front.c\
			ft_lstsize.c	ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c\
			ft_lstiter.c	ft_lstmap.c\

OBJ =		$(patsubst %.c,%.o,$(LIST))
OBJ_B =		$(patsubst %.c,%.o,$(LIST_B))

D_FILES =	$(patsubst %.c,%.d,$(LIST) $(LIST_B))

OPTFLAGS =	-O2
FLAGS =		-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ) $?

%.o:		%.c
			gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MMD

include $(wildcard $(D_FILES))

bonus:		$(OBJ_B)
			ar rcs $(NAME) $?

clean:
			rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
