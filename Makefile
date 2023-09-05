CC = gcc
EXEC = rush-01
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(EXEC)

%.o : %.c headerfile.h
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC)  -o $@ $^

clean :
	rm -rf *.o

fclean : clean
	rm -f $(EXEC)

re : fclean all

# $@ nom cible
# $< nom premiere dependance
# $^ liste dependances
# $? liste dependance plus recentes que la cible
# $* nom fichier, sans son extension

