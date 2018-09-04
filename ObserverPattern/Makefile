NAME	= ObserverPattern

SRC	= ./src/observerPattern.cpp

OBJ	 = $(SRC:.cpp=.o)

COMPILER = g++
CXXFLAGS = -std=c++17 -I./include


all:	$(NAME)

$(NAME):	$(OBJ)
	$(COMPILER) -o $(NAME) $(CXXFLAGS) $(OBJ) -g3
clean:
	rm -rf src/*.o

fclean:	clean
	rm -rf $(NAME)
	rm -rf ./*~

re:	fclean all
