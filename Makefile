##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-vivien.boitard
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

NAME	=	bsq

CFLAGS	=	-Wall -Wextra -I./include -g3

LDLIBS	=	-L./src/lib/my -lmy

CC	=	gcc

all:	$(NAME)

$(NAME):	$(SRC)
	make -C src/lib/my
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LDLIBS)

clean:
	make clean -C src/lib/my
	find . -type f -name "vgcore.*" -delete

fclean:	clean
	make clean -C src/lib/my
	rm -f $(NAME)

re:	fclean all
