/*
** main.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 22:09:17 2017 ROUX Hugues
** Last update Mon Jan 30 00:06:46 2017 ROUX Hugues
*/


#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	<stdlib.h>

/**
 * Fonction qui affiche la list des deux sens
 */
void		print_list(t_list *list)
{
  t_chain	*chain;
  char		*str;

  if (list == NULL || list->head == NULL)
    return;
  chain = list->head;
  while (chain->next != list->head)
    {
      str = chain->data;
      my_putstr(str);
      chain = chain->next;
    }
  str = chain->data;
  my_putstr(str);
  chain = list->head;
  while (chain->prev != list->head)
    {
      str = chain->data;
      my_putstr(str);
      chain = chain->prev;
    }
  str = chain->data;
  my_putstr(str);
}

/**
 * Test flot normal
 **/
t_list		*test1(char **argv)
{
  t_list	*list;
  t_chain	*chain;
  char		*str;

  list = init_list(&my_strcmp);
  while (*argv != NULL)
    {
      chain = init_chain(my_strdup(*argv));
      add_list(list, chain);
      argv++;
    }
  chain = search_ind(list, 2);
  if (chain != NULL)
    {
      str = chain->data;
      my_putstr(str);
    }
  print_list(list);
  return (list);
}

/**
 * Cas chaine vide
 **/
void		test2()
{
  t_list	*list;
  t_chain	*chain;

  list = init_list(&my_strcmp);
  chain = search_ind(list, 5);
  if (chain == NULL)
    my_putstr("Bon \n");
  chain = search_ind(list, -1);
  if (chain == NULL)
    my_putstr("Bon \n");
  chain = search_val(list, "888");
  if (chain == NULL)
    my_putstr("Bon \n");
  chain = init_chain("test");
  my_put_nbr(del_list(list, chain));
  free(chain);
  deinit_list(list);
}

/**
 *Test unitaire
 *
 **/
void		test3()
{
  t_list	*list;
  t_chain	*chain;
  
  list = init_list(NULL);
  if (list != NULL)
    deinit_list(list);
  add_list(NULL, NULL);
  chain = init_chain(NULL);
  if (chain != NULL)
    free(chain);
  search_ind(NULL, -1);
  search_val(NULL, NULL);
  del_list(NULL, NULL);
  deinit_list(NULL);
}

int		main(int argc, char **argv)
{
  t_list	*list;
  t_chain	*chain;
  char		*str;
    
  my_putstr("Test 1 :\n");
  list = test1(argv);
  chain = search_val(list, "./a.out");
  if (chain != NULL)
    {
      str = chain->data;
      my_putstr(str);
      del_list(list, chain);
    }
  print_list(list);
  deinit_list(list);
  my_putstr("Test 2 : \n");
  test2();
  my_putstr("Test 3 : \n");
  test3();
  if (argc == 0)
    my_putstr("test");
  return (0);
}
