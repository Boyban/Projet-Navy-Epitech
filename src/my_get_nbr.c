/*
** my_get_nbr.c for  in /home/yohan/Unix System Programmation/PSU_2016_navy_bootstrap
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Jan 30 12:24:51 2017 Yohan
** Last update Wed Feb  8 14:39:09 2017 Yohan Lequere
*/

#include "my.h"

int	my_get_nbr(char *str)
{
  int	i;
  int	mult;
  int	res;

  if (str == 0)
    return (-1);
  mult = 1;
  res = 0;
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      if ((str[i] - 48) < 0 || (str[i] - 48) > 9)
	return (-1);
      res = ((str[i] - 48) * mult) + res;
      mult = mult * 10;
      i = i - 1;
    }
  return (res);
}
