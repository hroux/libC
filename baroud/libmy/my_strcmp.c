/*
** my_strcmp.c for  in /home/hugues/DEVC/Jour04/roux_a/my_strcmp
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 13:21:50 2016 ROUX Hugues
** Last update Sun Jan 15 19:04:53 2017 ROUX Hugues
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL && s2 != NULL)
    return (-1);
  if (s2 == NULL && s1 != NULL)
    return (1);
  if (s2 == NULL && s1 == NULL)
    return (0);
  while (*s1 != '\0' && *s2 != '\0')
    {
      if (*s1 < *s2)
	return (-1);
      if (*s1 > *s2)
	return (1);
      s1 = s1 + 1;
      s2 = s2 + 1;
      if (*s1 == '\0' && *s2 != '\0')
	return (-1);
      if (*s2 == '\0' && *s1 != '\0')
	return (1);
    }
  return (0);
}
