NAME = libft.a

# directories
OBJDIR := objs
SRCDIR := src

# files with their paths
SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# compiler
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
HEADERS = -I ./includes

# prevents name collision with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): $(OBJS)
	@ar src $(NAME) $(OBJS)
	@echo "- $(NAME) built and ready"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "- $(NAME) cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "- $(NAME) fcleaned"

re: fclean all