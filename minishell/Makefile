RED="\033[1;31m"
GREEN='\033[3;32m'
NONE='\033[0m'

PREFIX = $(shell find ${HOME} -name ashhov_readline 2>/dev/null)

NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

SRCS = $(wildcard *.c) $(wildcard parsing_new/*.c) $(wildcard memory/*.c) $(wildcard builtin/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = -I./libft  -I./ashhov_readline/include

LINKERS	= -L./libft  -L./ashhov_readline/lib -lreadline -ltinfo

LINKERLIB = ./libft/libft.a

LIBFT = ./libft

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

# all: readline $(NAME)
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C $(LIBFT)
# @cp $(LINKERLIB) $(OBJS)
# @ar -rcs libminishell.a $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERLIB) $(LINKERS) -o $(NAME)
#  @$(CC) $(CFLAGS) $(LINKERS) $(INCLUDES) $(NAME) -o $(NAME)
	@echo $(NONE) $(GREEN)"       >Compiled< $(NAME)" $(NONE)

clean:
	@$(MAKE) clean -s -C $(LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT)
	@$(RM) $(NAME)
	@stty sane
	@echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

readline: 
	cd readline-master && make clean && ./configure --prefix=$(PREFIX) && make && make install

re: fclean all

norm: clean
	norminette $(SRCS)

.PHONY: all clean fclean re
