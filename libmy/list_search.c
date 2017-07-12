/*
** list_search.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Jan 11 22:36:56 2017 ROUX Hugues
** Last update Sun Jan 29 23:21:56 2017 ROUX Hugues
*/

#include	"libmy.h"
#include	"list.h"
#include	<stdlib.h>

t_chain		*search_ind(t_list *list, int ind)
{
  int		i;
  t_chain	*search;

  if (list == NULL)
    return (NULL);
  if (list->count <= ind || ind < 0)
    return (NULL);
  i = 0;
  search = list->head;
  while (i < ind)
    {
      search = search->next;
      i++;
    }
  return (search);
}

t_chain		*search_val(t_list *list, void *data)
{
  t_chain	*search;

  if (list == NULL)
    return (NULL);
  if (list->compare == NULL)
    return (NULL);
  search = list->head;
  if (search == NULL)
    return (NULL);
  while (search->next != list->head)
    {
      if (list->compare(search->data, data) == 0)
	return (search);
      search = search->next;
    }
  if (list->compare(search->data, data) == 0)
    return (search);
  else
    return (NULL);
}
