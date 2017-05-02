/*
** let_play.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 14:29:20 2017 Yohan Lequere
** Last update Sat Feb 18 13:19:10 2017 Yohan
*/

#include "gnl.h"
#include "my.h"

extern int	win;

void		connect_usr1(int i, siginfo_t *sig, void *s)
{
  static int	a = 0;

  if (a == 0)
    {
      my_putstr("\nsuccessfully connected\n\n");
      ++i;
    }
}

char	**complete_sentence(char **tab, int *arr, int pid)
{
  if (tab[arr[1]][arr[0]] == 'x')
    {
      tab[arr[1]][arr[0]] = 'x';
      kill(pid, SIGUSR2);
      my_putstr("missed\n\n");
    }
  else if (tab[arr[1]][arr[0]] < 48 || tab[arr[1]][arr[0]] > 57)
    {
      tab[arr[1]][arr[0]] = 'o';
      kill(pid, SIGUSR2);
      my_putstr("missed\n\n");
    }
  else
    {
      tab[arr[1]][arr[0]] = 'x';
      kill(pid, SIGUSR1);
      my_putstr("hit\n\n");
    }
  return (tab);
}

char	**know_case(int fd, char **tab, int pid, int *arr)
{
  char	*str;
  char	*list;

  list = CHAR_POS;
  str = check_sig();
  while (str[0] != list[arr[1]])
    {
      arr[0] = arr[0] + 2;
      ++arr[1];
    }
  arr[1] = str[1] - 48 + 1;
  if (arr[0] < 0 || arr[0] > 16 || arr[1] < 0 || arr[1] > 9)
    return (NULL);
  my_putstr(str);
  my_putstr(": ");
  return (tab = complete_sentence(tab, arr, pid));
}

int	loop_wait(int *who, char **tab, char **user1, struct sigaction signal)
{
  int	fd;
  int	arr[2];

  arr[0] = 2;
  arr[1] = 0;
  my_putstr("\nwaiting for enemy's attack\n");
  signal.sa_sigaction = hole;
  sigaction(SIGUSR1, &signal, NULL);
  pause();
  if ((tab = know_case(-1, tab, who[0], arr)) == NULL);
  show_status(tab, user1);
  win_or_not(tab, user1);
  if (win == 0 || win == 1)
    return (win);
  play(who, tab, user1, signal);
}

int			let_play(int pid, char **av, char **tab)
{
  struct sigaction	signal;
  char			**user1;
  int			who[2];
  int			i;

  who[0] = pid;
  who[1] = 1;
  signal.sa_sigaction = connect_usr1;
  signal.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &signal, NULL);
  pause();
  user1 = dump_map();
  while (1)
    {
      if (win == 0 || win == 1)
	return (win);
      my_putstr("my_positions:\n");
      my_show_tab(tab);
      my_putstr("\nenemy's positions:\n");
      my_show_tab(user1);
      i = loop_wait(who, tab, user1, signal);
      if (i == 1 || i == 0)
	return (i);
    }
}
