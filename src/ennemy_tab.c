/*
** ennemy_tab.c for  in /media/yohan/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Feb  6 17:00:45 2017 Yohan
** Last update Wed Feb  8 11:09:11 2017 Yohan Lequere
*/

#include "my.h"

#define CHAR_POS	"ABCDEFGH"

extern int	win;

char	**ennemy_tab(char *str, char **user1)
{
  char	*list;
  int	i;
  int	j;

  i = 0;
  j = 2;
  list = CHAR_POS;
  while (str[0] != list[i])
    {
      j = j + 2;
      ++i;
    }
  i = 1;
  while (str[1] != 48)
    {
      ++i;
      str[1] = str[1] - 1;
    }
  if (win == 4)
    user1[i][j] = 'x';
  else if (win == 5)
    user1[i][j] = 'o';
  return (user1);
}
