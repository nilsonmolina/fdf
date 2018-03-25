# gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c
gcc -g src/*.c -I libft -I libft/includes -L libft -lft -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
#gcc -g src/*.c -I libft2 -L libft2 -lft -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
