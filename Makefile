NAME = mpinson.filler

SRC = ./srcs/main.c ./srcs/ft_resolv.c ./srcs/get_plateau.c ./srcs/get_piece.c ./srcs/check_place.c

SRC_MLX = ./srcs/main_mlx.c ./srcs/ft_resolv.c ./srcs/get_plateau.c ./srcs/get_piece.c ./srcs/draw.c ./srcs/check_place.c

FLAGS = -Wall -Wextra -Werror

SRC2 = ./main.o ./ft_resolv.o ./get_plateau.o ./get_piece.o ./draw.o ./check_place.o

SRC2_MLX = ./main_mlx.o ./ft_resolv.o ./get_plateau.o ./get_piece.o ./draw.o ./check_place.o

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -I ./include/ -L./lib -lft -o $(NAME) $(SRC)

mlx: $(SRC_MLX)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -I ./include/ -L/usr/local/lib/ -L./lib -I/usr/local/include -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC_MLX)

clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

clean_mlx:
	/bin/rm -f $(SRC2_MLX)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

fclean_mlx: clean_mlx
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

re_mlx: fclean_mlx mlx
