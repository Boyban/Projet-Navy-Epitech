/*
** my.h for  in /media/yohan/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/Yohan/Sem_2/PSU_2016_navy
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Feb  6 09:41:42 2017 Yohan
** Last update Thu Feb 16 15:20:12 2017 Yohan
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define CHAR_POS        "ABCDEFGH"

char    **make_me_boats(char *str, char **tab);
char    **dump_map();
int     *dump_who(int *who);
void    aff_screen();
void    connect(int i, siginfo_t *sig, void *s);
int     client_one(char **av);
int     client_two(char **av);
char    **ennemy_tab(char *str, char **user1);
void    hole(int i, siginfo_t *sig, void *s);
int     play(int *who, char **tab, char **user1, struct sigaction signal);
void    connect_usr1(int i, siginfo_t *sig, void *s);
char    **complete_sentence(char **tab, int *arr, int pid);
char    **know_case(int fd, char **tab, int pid, int *arr);
int     loop_wait(int *who, char **tab, char **user1, struct sigaction signal);
int     let_play(int pid, char **av, char **tab);
int     my_get_nbr(char *str);
char    *my_intostr(int nb);
void    my_putchar(char c);
int     my_putf(char *str, char *path);
void    my_show_tab(char **tab);
char    **so_boat(char **tab, char *str, int pos, int length);
char    **linear_boat(char **tab, char *str, int pos, int length);
char    **dump_map();
char    **good_boat(char *str, char **tab);
char    **make_me_boats(char *str, char **tab);
int     loop_wait(int *who, char **tab, char **user1, struct sigaction signal);
char    **ennemy_tab(char *str, char **user1);
int     *dump_who(int *who);
void    hit(int i, siginfo_t *sig, void *s);
int     check_coordinate(char *str, char **user1);
void    show_status(char **tab, char **user1);
int     play(int *who, char **tab, char **user1, struct sigaction signal);
int	my_putstr(char *str);
int	my_strlen(char *str);
int     navy(int ac, char **av, int i);
int     my_put_nbr(int nb);
int     win_or_not(char **tab, char **user1);
int	loop_sig(char *str, int pid);
char    *check_sig();
char    **for_play(char *str, int pid, struct sigaction signal, char **user1);
int	check_boat(int c, char *str);

#endif /* !MY_H_ */
