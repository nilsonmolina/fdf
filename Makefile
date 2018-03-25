NAME = fdf

# file names
SRC = main.c 
OBJ = $(SRC:.c=.o)

# directories
SRCDIR = src
OBJDIR = objs
LIBDIR = libs/libft
MLXDIR = libs/minilibx

# files with their paths
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

# compiler
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra 
LIBS = $(LIBDIR)/libft.a -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit
HEADERS = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

# prevent name collisions with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "- fdf ready"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean
	@echo "- fdf cleaned"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@echo "- fdf fcleaned"

re: fclean all