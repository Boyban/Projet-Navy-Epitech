/*
** check_boat.c for  in /home/yohan/PSU_2016_navy
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Tue Feb 14 17:08:28 2017 Yohan
** Last update Sun Feb 19 00:21:40 2017 Yohan Lequere
*/

#include "my.h"

int	check_line(char *str)
{
  if (str[0] < 48 || str[0] >= 57 || str[1] != ':')
    return (-1);
  if (str[2] < 65 || str[2] > 72 || str[5] < 65 || str[5] > 72)
    return (-1);
  if (str[3] < 48 || str[3] >= 57 || str[4] != ':')
    return (-1);
  if (str[6] < 48 || str[6] >= 57)
    return (-1);
}

int	check_boat(int c, char *str)
{
  static int	nb = 0;
  static int	pass = 0;
  static int	for_2 = 0;

  nb = nb + c;
  pass = pass + 1;
  if (c == 2)
    for_2 = for_2 + 2;
  if (c == 3)
    for_2 = for_2 + 3;
  if (c == 4)
    for_2 = for_2 + 4;
  if (c == 5)
    for_2 = for_2 + 5;
  if (pass > 4)
    return (-1);
  if (nb == 14 && for_2 != 14)
    return (-1);
  if (nb > 14)
    return (-1);
  if (check_line(str) == -1)
    return (-1);
  else
    return (0);
}
