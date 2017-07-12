/*
** my_strdup.c for  in /home/hugues/DEVC/Jour07/roux_a/my_strdup
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Oct 24 11:47:33 2016 ROUX Hugues
** Last update Sun Jan 29 16:01:48 2017 ROUX Hugues
*/

#include	<stdlib.h>
#include	"libmy.h"

char		*my_strdup(char *str)
{
  char		*dest;
  int		len;

  len = my_strlen(str);
  dest = malloc((len + 1) * sizeof(str));
  if (dest == NULL)
    {
      return (NULL);
    }
  my_strcpy(dest, str);
  return (dest);
}
