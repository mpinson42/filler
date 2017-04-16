NAME = mpinson.filler

SRC = ./srcs/main.c ./srcs/ft_resolv.c ./srcs/get_plateau.c ./srcs/get_piece.c ./srcs/draw.c ./srcs/check_place.c


FLAGS = -Wall -Wextra -Werror

SRC2 = ./main.o ./ft_resolv.o ./get_plateau.o ./get_piece.o ./draw.o ./check_place.o

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc $(FLAGS) -g -I ./include/ -L/usr/local/lib/ -L./lib -I/usr/local/include -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
