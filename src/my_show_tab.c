/*
** my_show_tab.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 09:40:27 2017 Yohan Lequere
** Last update Wed Feb  8 14:26:33 2017 Yohan Lequere
*/

#include "my.h"

void	my_show_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      ++i;
    }
}
