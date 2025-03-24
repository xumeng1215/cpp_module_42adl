CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
INC_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

EXEC = convert

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
