NAME 	= bureaucrat
CPP 	= @c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror
SRCS 	= main.cpp Bureaucrat.cpp

all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all