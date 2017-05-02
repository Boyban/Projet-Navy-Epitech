/*
** my_putf.c for  in /home/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Thu Feb  2 13:11:17 2017 Yohan Lequere
** Last update Wed Feb  8 14:26:12 2017 Yohan Lequere
*/

#include "gnl.h"
#include "my.h"

int	my_putf(char *str, char *path)
{
  int	fd;

  fd = open(path, O_WRONLY);
  write(fd, str, my_strlen(str));
}
