/*
** my_putchar.c for  in /home/hugues/DEVC/Jour01/my_putchar
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Oct 17 09:53:41 2016 ROUX Hugues
** Last update Mon Oct 17 11:23:10 2016 ROUX Hugues
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
