NAME = philosophers
HEADER = philosophers.h
CFLAGS = -Wall -Werror -Wextra -g -pthread 
SRC = philo.c \
	  ft_split.c \
	  ft_strjoin.c \
	  ft_calloc.c \
	  ft_bzero.c \
	  ft_substr.c \
	  ft_memset.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  parsing.c \
	  ft_atoi.c \
	  extra2.c \
	  philo_func.c \
	  new_list.c 

CC = cc
RM = rm -rf

all: $(NAME)


$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME) $(NAMEB)

fclean: clean
	$(RM) 

re: fclean all