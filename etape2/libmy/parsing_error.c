/*
** parsing_error.c for  in /home/hugues/Documents/C/lib/libmy
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sun Jan 29 21:08:35 2017 ROUX Hugues
** Last update Wed Feb 22 22:09:51 2017 ROUX Hugues
*/

#include	"list.h"
#include	"parse.h"
#include	"libmy.h"
#include	<stdlib.h>

void		print_error_arg(t_arg *arg)
{
  int		i;

  i = 0;
  if (arg == NULL)
    return;
  if (arg->count_arg < 0)
    my_putstr("arg ... \n");
  else if (arg->count_arg > 0)
    {
      while (i < arg->count_arg)
	{
	  my_putstr("arg ");
	  i++;
	}
      my_putchar('\n');
    }
  else
    my_putstr(my_strdup("Aucun arguments \n"));
}

void		print_error_opt(t_arg *arg)
{
  t_chain	*chain;
  t_parsing	*parsing;
  int		i;

  my_putstr("Erreur usage : \n");
  if (arg == NULL)
    return;
  if (arg->list_opt == NULL)
    return;
  print_error_arg(arg);
  chain = arg->list_opt->head;
  i = 0;
  while (i != arg->list_opt->count)
    {
      parsing = chain->data;
      if (parsing != NULL)
	{
	  my_putstr(parsing->opt);
	  my_putstr("\t\t\t\t");
	  my_putstr(parsing->help);
	  my_putstr("\n");
	}
      chain = chain->next;
      i++;
    }
}
