/*
** loop_sig.c for  in /home/yohan/PSU_2016_navy
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Feb 13 16:40:09 2017 Yohan
** Last update Tue Feb 14 15:47:21 2017 Yohan
*/

#include "my.h"

extern int	win;

void	hole_2(int i, siginfo_t *sig, void *s)
{
  static int	c = 0;

  if (i == SIGUSR1)
    {
      c = c + 1;
      win = c;
    }
  else if (i == SIGUSR2)
    {
      c = 0;
      win = 14;
    }
}

int	loop_sig(char *str, int pid)
{
  int	c;
  int	nb;

  c = str[0] - 64;
  nb = str[1] - 48;
  while (c != 0)
    {
      kill(pid, SIGUSR1);
      c = c - 1;
      usleep(1);
    }
  kill(pid, SIGUSR2);
  usleep(1);
  while (nb != 0)
    {
      kill(pid, SIGUSR1);
      nb = nb - 1;
      usleep(1);
    }
  kill(pid, SIGUSR2);
  return (1);
}

char		*check_sig()
{
  char			*str;
  struct sigaction	signal;

  str = malloc(sizeof(char) * 2);
  signal.sa_sigaction = hole_2;
  signal.sa_flags = SA_SIGINFO;
  win = 0;
  sigaction(SIGUSR1, &signal, NULL);
  sigaction(SIGUSR2, &signal, NULL);
  while (win != 14)
    {
      str[0] = win + 65;
      usleep(1);
    }
  win = 0;
  while (win != 14)
    {
      str[1] = win + 48;
      usleep(1);
    }
  str[2] = '\0';
  win = 10;
  return (str);
}
