NAME	= Port
CXX		= g++
FLAGS	= -Wall -Wextra -Werror
SRC		= main.cpp port.cpp vintage_port.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o:    %.cpp
		$(CXX) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
