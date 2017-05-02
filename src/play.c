/*
** play.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Fri Feb  3 15:05:01 2017 Yohan Lequere
** Last update Sat Feb 18 12:35:46 2017 Yohan
*/

#include "gnl.h"
#include "my.h"

extern int	win;

int	*dump_who(int *who)
{
  int	fd;

  who = malloc(sizeof(int) * 2);
  who[0] = win;
  who[1] = 0;
  win = 10;
  return (who);
}

void	hit(int i, siginfo_t *sig, void *s)
{
  if (i == SIGUSR1)
    {
      my_putstr("hit\n\n");
      win = 4;
    }
  if (i == SIGUSR2)
    {
      my_putstr("missed\n\n");

      win = 5;
    }
}

int	check_coordinate(char *str, char **user1)
{
  int	c;

  if (str == NULL)
    {
      my_putstr("wrong position");
      return (-1);
    }
  if (str[0] == '\0'|| str[1] == '\0' || my_strlen(str) > 2)
    {
      my_putstr("wrong position");
      return (-1);
    }
  if ((str[0] - 65) < 0 || (str[0] - 65) >= 8 || str[1] <= 48 || str[1] > 56)
    {
      my_putstr("wrong position");
      return (-1);
    }
  return (1);
}

void	show_status(char **tab, char **user1)
{
  my_putstr("my_positions:\n");
  my_show_tab(tab);
  my_putstr("\nenemy's positions:\n");
  my_show_tab(user1);
}

int	play(int *who, char **tab, char **user1, struct sigaction signal)
{
  char	*str;

  win_or_not(tab, user1);
  if (win == 0 || win == 1)
    return (win);
  while (1)
    {
      my_putstr("\nattack:\t");
      str = get_next_line(0);
      my_putstr(str);
      my_putstr(": ");
      if (check_coordinate(str, user1) == 1)
	{
	  user1 = for_play(str, who[0], signal, user1);
	  show_status(tab, user1);
	  win_or_not(tab, user1);
	  if (win == 0 || win == 1)
	    return (win);
	  loop_wait(who, tab, user1, signal);
	  if (win == 0 || win == 1)
	    return (win);
	}
      else;
    }
}
