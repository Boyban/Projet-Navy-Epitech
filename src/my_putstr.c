/*
** my_putstr.c for  in /home/yohan/Unix System Programmation/PSU_2016_navy_bootstrap
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Jan 30 11:23:41 2017 Yohan
** Last update Wed Feb  8 14:39:27 2017 Yohan Lequere
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
