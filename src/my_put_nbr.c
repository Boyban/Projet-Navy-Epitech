/*
** main.c for my_put_nbr in /home/Yohan/Day03
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Wed Oct  5 22:50:59 2016 Yohan Lequere
** Last update Wed Feb  8 14:30:43 2017 Yohan Lequere
*/

#include "my.h"

int	count1(int nbr)
{
  int	count;

  count = 1;
  while (nbr > 9)
    {
      nbr = nbr / 10;
      count = count * 10;
    }
  return (count);
}

int		display_n(int nb)
{
  int count;
  long int	results;

  results = 0;
  count = count1(nb);
  my_putchar('-');
  while (nb >= 0)
    {
      if (count == 1)
    {
      my_putchar(nb + 48);
      nb = -1;
    }
    else
      {
	results = nb / count;
	nb = nb % count;
	count = count / 10;
	my_putchar(results + 48);
      }
    }
}

int	display_p(int nb)
{
  int	count;
  long	results;
  int	i;

  i = 0;
  results = 0;
  count = count1(nb);
  while (nb >= 0)
    {
      if (count == 1)
	{
	  my_putchar(nb + 48);
	  nb = -1;
	  i = i + 1;
	}
      else
	{
	  results = nb / count;
	  nb = nb % count;
	  count = count / 10;
	  my_putchar(results + 48);
	  i = i + 1;
	}
    }
  return (i);
}

int    	my_put_nbr(int nb)
{
  if (nb >= 0)
    {
      display_p(nb);
    }
  else
	 {
	   nb = nb * -1;
	   display_n(nb);
	 }
}
