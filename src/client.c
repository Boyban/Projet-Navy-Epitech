/*
** client.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 10:26:36 2017 Yohan Lequere
** Last update Sun Feb 19 00:14:54 2017 Yohan Lequere
*/

#include "gnl.h"
#include "my.h"

extern int	win;

void	aff_screen()
{
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  my_putstr("\nwaiting for ennemy connexion...\n");
}

void	connect(int i, siginfo_t *sig, void *s)
{
  win = sig->si_pid;
  my_putstr("enemy connected\n\n");
  if (kill(win, SIGUSR1) == -1);
}

int			client_one(char **av)
{
  struct sigaction	signal;
  char			**tab;
  char			**user2;
  int			*who;

  tab = dump_map();
  user2 = dump_map();
  signal.sa_sigaction = connect;
  signal.sa_flags = SA_SIGINFO;
  if ((tab = make_me_boats(av[1], tab)) == NULL)
    return (-1);
  aff_screen();
  sigaction(SIGUSR2, &signal, NULL);
  pause();
  who = dump_who(who);
  while (1)
    {
      my_putstr("my_positions:\n");
      my_show_tab(tab);
      my_putstr("\nenemy's positions:\n");
      my_show_tab(user2);
      play(who, tab, user2, signal);
      if (win == 0 || win == 1)
	return (win);
    }
}

int	client_two(char **av)
{
  char	**tab;
  int	pid;

  tab = dump_map();
  if ((pid = my_get_nbr(av[1])) == -1)
    return (-1);
  my_putstr("my_pid:\t");
  my_put_nbr(getpid());
  if ((tab = make_me_boats(av[2], tab)) == NULL)
    return (-1);
  if (kill(pid, SIGUSR2) == -1)
    return (-1);
  else
    let_play(pid, av, tab);
  return (0);
}
