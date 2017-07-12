/*
** my_putstr.c for  in /home/hugues/DEVC/Jour03/roux_a/my_putstr
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:24:02 2016 ROUX Hugues
** Last update Sun Jan 29 16:02:55 2017 ROUX Hugues
*/

#include	<stdlib.h>
#include	"libmy.h"

void		my_putstr(char *str)
{
  if (str == NULL)
    return;
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
