/*
** navy.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Wed Feb  1 16:49:38 2017 Yohan Lequere
** Last update Mon May  1 10:42:48 2017 Yohan
*/

#include "gnl.h"
#include "my.h"

#define CHAR_POS	"ABCDEFGH"

char	**so_boat(char **tab, char *str, int pos, int length);
char	**linear_boat(char **tab, char *str, int pos, int length);
void	my_show_tab(char **tab);

extern int	win;

char	**dump_map()
{
  char	**tab;
  int	i;
  int	fd;

  i = 0;
  tab = malloc(sizeof(char *) * 10);
  fd = open("./log/map.txt", O_RDONLY);
  while (i != 10)
{
      tab[i] = get_next_line(fd);
      ++i;
    }
  tab[i] = 0;
  return (tab);
}

char	**good_boat(char *str, char **tab)
{
  int	c;
  int	j;
  int	i;
  char	*list;
  int	pos;

  list = CHAR_POS;
  j = 2;
  i = 0;
  pos = 2;
  c = str[0] - 48;
  if (check_boat(c, str) == -1 || my_strlen(str) != 7)
    return (NULL);
  while (str[2] != list[i])
    {
      pos = pos + 2;
      ++i;
    }
  if (((str[2] == str[5]) && (str[3] != str[6])) || (c == 1))
    tab = so_boat(tab, str, pos, c);
  else if ((str[2] != str[5]) && (str[3] == str[6]))
    tab = linear_boat(tab, str, pos, c);
  else
    return (NULL);
  return (tab);
}

char	**make_me_boats(char *str, char **tab)
{
  int	fd;
  char	*s;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (NULL);
  while ((s = get_next_line(fd)) != NULL)
    {
      if ((tab = good_boat(s, tab)) == NULL)
	return (NULL);
    }
  return (tab);
}

int	navy(int ac, char **av, int i)
{
  if (ac == 2)
    if (client_one(av) == -1)
      {
	my_putstr("Invalid coordinate or file\n");
	return (-1);
      }
  if (ac == 3)
    if (client_two(av) == -1)
      {
	my_putstr("Invalid coordinate, file or PID connexion\n");
	return (-1);
      }
}
