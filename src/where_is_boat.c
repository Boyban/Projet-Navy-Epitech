/*
** where_is_boat.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 09:25:12 2017 Yohan Lequere
** Last update Wed Feb  8 14:35:52 2017 Yohan Lequere
*/

#include "my.h"

char	**so_boat(char **tab, char *str, int pos, int length)
{
  int	from;
  int	to;
  int	tmp;

  if (str[3] <= str[6])
    {
      from = str[3] - 48;
      to = str[6] - 48;
    }
  else
    {
      from = str[6] - 48;
      to = str[3] - 48;
    }
  tmp = length + 48;
  if (to - from != length - 1)
    return (NULL);
  from = from + 1;
  while (length > 0)
    {
      tab[from][pos] = tmp;
      length = length - 1;
      from = from + 1;
    }
  return (tab);
}

char	**linear_boat(char **tab, char *str, int pos, int length)
{
  int	from;
  int	to;
  int	tmp;

  tmp = length + 48;
  from = (str[3] - 48) + 1;
  while (length > 0)
    {
      tab[from][pos] = tmp;
      pos = pos + 2;
      length = length - 1;
    }
  return (tab);
}
