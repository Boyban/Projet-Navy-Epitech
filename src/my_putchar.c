/*
** my_putchar.c for  in /home/yohan/Unix System Programmation/PSU_2016_navy_bootstrap
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Jan 30 11:23:18 2017 Yohan
** Last update Wed Feb  8 14:40:16 2017 Yohan Lequere
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
