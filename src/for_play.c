/*
** for_play.c for  in /home/yohan/PSU_2016_navy
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Tue Feb 14 15:52:54 2017 Yohan
** Last update Tue Feb 14 16:17:47 2017 Yohan
*/

#include "my.h"

char	**for_play(char *str, int pid, struct sigaction signal, char **user1)
{
  loop_sig(str, pid);
  signal.sa_sigaction = hit;
  sigaction(SIGUSR1, &signal, NULL);
  sigaction(SIGUSR2, &signal, NULL);
  pause();
  user1 = ennemy_tab(str, user1);
  return (user1);
}
