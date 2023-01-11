# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 19:17:29 by hvardany          #+#    #+#              #
#    Updated: 2022/11/12 19:57:04 by hvardany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= $(wildcard *.c)

OBJ	= $(patsubst %.c, %.o, $(SRCS))

NAME	= libft.a

CC		= cc

WALL	= -Wall -Werror -Wextra

RMIF		= rm -f

%.o: %.c
	@$(CC) $(WALL) -c $< -o $@

all:		$(NAME)

$(NAME): $(OBJ)
			@ar rcs $(NAME) $(OBJ)


clean:
	@$(RMIF) $(OBJ)

fclean:	clean
	@$(RMIF)	$(NAME)

bonus:		$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
