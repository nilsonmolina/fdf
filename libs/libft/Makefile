SRCDIR = src
OBJDIR = obj

SRC = ft_*.c 
OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a

# prevents name collision with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(HEADER) $(SRCS)
	@/bin/mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)/
	@ar src $(NAME) $(OBJS)

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all