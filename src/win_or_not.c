/*
** win_or_not.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Sat Feb  4 06:37:22 2017 Yohan Lequere
** Last update Tue Feb 14 18:05:57 2017 Yohan
*/

extern int win;

int	win_or_not(char **tab, char **user1)
{
  int	i;
  int	j;
  int	x;
  int	c;

  i = 0;
  x = 0;
  c = 0;
  while (tab[i] != 0)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'x')
	    ++x;
	  if (user1[i][j] == 'x')
	    ++c;
	  ++j;
	}
      ++i;
    }
  if (x == 12)
    win = 1;
  else if (c == 12)
    win = 0;
}
