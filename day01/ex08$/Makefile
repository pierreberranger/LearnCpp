C = clang++

NAME = ex08

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

SOURCES = main.cpp Human.cpp

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
