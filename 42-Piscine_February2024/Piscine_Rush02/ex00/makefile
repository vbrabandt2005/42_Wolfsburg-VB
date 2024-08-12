
NAME = Capybara_Rush
MAIN_DICTIONARY = numbers.dict

$(NAME):
	@gcc -Wall -Wextra -Werror main.c -o $(NAME)

clean:
	@find . -name $(NAME) -delete

fclean: clean
	@find data -name *.dict -not -name $(MAIN_DICTIONARY) -delete
