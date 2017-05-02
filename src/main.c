/*
** main.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Wed Feb  1 16:06:28 2017 Yohan Lequere
** Last update Wed Feb  8 14:24:45 2017 Yohan Lequere
*/

#include "my.h"

int	win = 10;

int	main(int ac, char **av)
{
  int	fd;
  char	buffer[1];

  if (ac == 2)
    {
      if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
	{
	  fd = open("./log/help.txt", O_RDONLY);
	  while (read(fd, buffer, 1) != 0)
	    write(1, buffer, 1);
	  return (0);
	}
    }
  if (ac == 1 || ac > 3)
    {
      my_putstr("navy: Invalid options, try --h for see help\n");
      return (84);
    }
  navy(ac, av, -1);
  if (win == 1)
    my_putstr("Enemy won\n");
  else if (win == 0)
    my_putstr("I won\n");
  return (win);
}
