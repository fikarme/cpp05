NAME 	= bureaucrat
CPP 	= @c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror
SRCS 	= 	main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all