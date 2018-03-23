# gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c
gcc -g src/*.c -I libft -L libft -l ft -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
