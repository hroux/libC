/*
** list.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 23:11:43 2017 ROUX Hugues
** Last update Sun Feb 12 21:03:12 2017 ROUX Hugues
*/

#include	"list.h"
#include	<stdlib.h>

t_list		*init_list(int (*comp)())
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  if (list == NULL)
    return (NULL);
  list->head = NULL;
  list->count = 0;
  list->compare = comp;
  return (list);
}

int		add_list(t_list *list, t_chain *chain)
{ 
  if (list == NULL)
    return (1);
  if (chain == NULL)
    return (1);
  chain->index = list->count + 1;
  if (list->head == NULL)
    list->head = chain;
  else
    {
      chain->prev = list->head->prev;
      chain->prev->next = chain;
    }
  list->count++;
  list->head->prev = chain;
  chain->next = list->head;
  return (0);
}

t_chain		*init_chain(void *data)
{
  t_chain	*chain;

  chain = malloc(sizeof(t_chain));
  if (chain == NULL)
    return (NULL);
  chain->index = 0;
  chain->data = data;
  chain->next = NULL;
  chain->prev = NULL;
  return (chain);
}
