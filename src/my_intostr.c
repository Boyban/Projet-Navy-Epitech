/*
** my_intostr.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 13:29:51 2017 Yohan Lequere
** Last update Wed Feb  8 14:42:03 2017 Yohan Lequere
*/

#include "my.h"

int	count_chiff(int nb)
{
  int	count;
  int	tmp;
  int	i;

  i = 0;
  count = 10;
  tmp = nb;
  while (nb > 10)
    {
      nb = tmp / count;
      count = count * 10;
      ++i;
    }
  if (nb > 0)
    ++i;
  return (i);
}

char	*my_intostr(int nb)
{
  char	*str;
  int	i;
  int	count;

  count = 1;
  i = count_chiff(nb);
  str = malloc(sizeof(char) * i);
  while (i > 1)
    {
      --i;
      count = count * 10;
    }
  i = 0;
  while (count >= 1)
    {
      str[i] = (nb / count) + 48;
      nb = nb % count;
      count  = count / 10;
      ++i;
    }
  return (str);
}
