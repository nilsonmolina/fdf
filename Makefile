NAME = fdf

# file names
SRC = main.c events.c render.c scanner.c prepare.c mutate.c
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
HEADERS = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)
# final
CFLAGS = -c -Wall -Werror -Wextra
LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

# # debug - fsanitize
# CFLAGS = -c -g -Wall -Werror -Wextra -fsanitize=address
# LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit -fsanitize=address

# # debug - VSCode lldb debugger
# CFLAGS = -c -g -Wall -Werror -Wextra 
# LIBS = -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit


# prevent name collisions with files in the directory.
.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "[$(CC)] - $<"
	@$(CC) $(CFLAGS) $(HEADERS) $< -o $@

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "---- $(NAME) built and ready ----"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean
	@echo "---- $(NAME) cleaned ----"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "---- $(NAME) fcleaned ----"

re: fclean all
