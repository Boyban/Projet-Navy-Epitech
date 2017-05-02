##
## Makefile for  in /home/Yohan/Sem_2/PSU_2016_navy
## 
## Made by Yohan Lequere
## Login   <Yohan@epitech.net>
## 
## Started on  Wed Feb  1 16:51:53 2017 Yohan Lequere
## Last update Tue Feb 14 18:30:15 2017 Yohan
##

SRC	= 	src/main.c		\
		src/navy.c		\
		src/my_get_nbr.c	\
		src/my_putstr.c		\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/where_is_boat.c	\
		src/my_show_tab.c	\
		src/client.c		\
		src/my_putf.c		\
		src/my_intostr.c	\
		src/let_play.c		\
		src/hole.c		\
		src/play.c		\
		src/win_or_not.c	\
		src/ennemy_tab.c	\
		src/loop_sig.c		\
		src/for_play.c		\
		src/check_boat.c	

OBJ	=	$(SRC:.c=.o)

LIBS	=	-L. -lgnl -L ./includes/-lgnl

FLAGS	=	-I. -I ./includes

NAME	=	navy

all: $(NAME)

$(NAME):	$(SRC)
		gcc -o $(NAME) $(SRC) $(LIBS) $(FLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
