NAME= push_swap
CC= cc
FLAGS= -g

SRC= ft_atoi.c parsing.c stack_utils.c\
	move_a_ab.c move_b_ab.c move_ab.c\
	move_a.c move_b.c count_disorder.c\
	strat_utils.c ft_sqrt.c\
	medium_strategy.c adaptive_strategy.c push_swap.c\
	main.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
