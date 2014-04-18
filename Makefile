##
## Makefile for  in /home/aube_a/rendu/piscine_cpp_rush2/ChapterIII
## 
## Made by Anthony Aube
## Login   <aube_a@epitech.net>
## 
## Started on  Sun Jan 19 04:26:13 2014 Anthony Aube
## Last update Sat Feb 15 17:51:53 2014 Mehdi Chouag
##

SRC		= src/malloc.c \
		  src/memory.c \
		  src/function_list.c \

OBJ		= $(SRC:.c=.o)

NAME		= libmy_malloc_$(HOSTTYPE).so

CFLAGS		= -c -fPIC -Wall -Wextra -Werror -I ./header


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(SRC) $(CFLAGS)
	gcc -shared $(OBJ) -o $(NAME)
	rm -f *.o 
	ln -s $(NAME) libmy_malloc.so
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libmy_malloc.so

re: fclean all
