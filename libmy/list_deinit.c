/*
** list_deinit.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 23:41:19 2017 ROUX Hugues
** Last update Sun Jan 29 23:18:52 2017 ROUX Hugues
*/

#include	"list.h"
#include	"libmy.h"
#include	<stdlib.h>

int		del_list(t_list *list, t_chain *chain)
{
  t_chain	*temp;

  if (chain == NULL || list == NULL || list->head == NULL)
    return (1);
  temp = list->head;
  while (temp->next != list->head && temp != chain)
    temp = temp->next;
  if (temp != chain)
    return (1);
  chain->next->prev = chain->prev;
  chain->prev->next = chain->next;
  if (chain == list->head)
    list->head = chain->next;
  if (chain->data != NULL)
    free(chain->data);
  free(chain);
  list->count--;
  if (list->count == 0)
    list->head = NULL;
  return (0);
}

int		deinit_list(t_list *list)
{
  t_chain	*chain;
  t_chain	*next;

  if (list == NULL)
    return (1);
  chain = list->head;
  if (chain != NULL)
    {
      while (list->count > 0)
	{
	  next = chain->next;
	  del_list(list, chain);
	  chain = next;
	}
    }
  free(list);
  return (0);
}
