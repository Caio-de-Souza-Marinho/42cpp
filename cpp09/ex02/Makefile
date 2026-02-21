NAME	= PmergeMe
CC	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

TEST_INPUT = `shuf -i 1-100 -n 10 | tr "\n" " "`

SRC	= ./main.cpp \
	  ./PmergeMe.cpp

OBJ	= ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${OBJ}

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

run: re
	./${NAME} ${TEST_INPUT}

.PHONY: all clean fclean re run
