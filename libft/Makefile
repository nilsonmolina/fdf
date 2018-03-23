NAME = libft.a
FLAGS = -Wall -Wextra -Werror
C_FILES = ft_*.c
O_FILES = ft_*.o

$(NAME):
	@gcc -c $(FLAGS) $(C_FILES)
	@ar rc $(NAME) $(O_FILES) libft.h
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(O_FILES)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all
