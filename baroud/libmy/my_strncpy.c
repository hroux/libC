/*
** my_strncpy.c for  in /home/hugues/DEVC/Jour04/roux_a/my_strncpy
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Fri Oct 21 11:33:04 2016 ROUX Hugues
** Last update Sun Feb 12 21:25:06 2017 ROUX Hugues
*/

#include	<stdlib.h>

void	test_end(int	*bool_end, char *src)
{
  if (*src == '\0')
    *bool_end = 1;
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;
  int	bool_end;
  char	*dstp;

  if (dest == NULL || src == NULL)
    return (NULL);
  count = 0;
  dstp = dest;
  bool_end = 0;
  while (count < n)
    {
      test_end(&bool_end, src);
      if (bool_end == 0)
	{
	  *dstp = *src;
	  src = src + 1;
	}
      else
	*dstp = 0;
      count = count + 1;
      dstp = dstp + 1;
    }
  return (dest);
}
