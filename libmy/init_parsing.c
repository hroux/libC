/*
** init_parsing.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sun Jan 15 22:16:33 2017 ROUX Hugues
** Last update Sun Jan 29 21:16:08 2017 ROUX Hugues
*/

#include	"list.h"
#include	"parse.h"
#include	"libmy.h"
#include	<stdlib.h>

t_parsing	*init_pars(char *opt, void (*do_fnc)(),
			   char *help, void *defaut)
{
  t_parsing	*parsing;

  parsing = malloc(sizeof(t_parsing));
  if (parsing == NULL)
    return parsing;
  parsing->opt = opt;
  parsing->do_fnc = do_fnc;
  parsing->help = help;
  parsing->defaut = defaut;
  return (parsing);
}

t_arg		*init_arg(int count_arg, t_list *list)
{
  t_arg		*arg;

  arg = malloc(sizeof(t_arg));
  if (arg == NULL)
    return arg;
  arg->list_opt = list;
  arg->count_arg = count_arg;
  arg->list_arg = init_list(my_strcmp);
  return (arg);
}

void		deinit_arg(t_arg *arg)
{
  if (arg == NULL)
    return;
  if (arg->list_opt != NULL)
    deinit_list(arg->list_opt);
  if (arg->list_arg != NULL)
    deinit_list(arg->list_arg);
  free(arg);
}

int		check_arg_opt(t_arg *arg, char **argv)
{
  if (init_option(arg, argv) != 0)
    {
      print_error_opt(arg);
      return (-1);
    }
  if (arg->count_arg == -1 && arg->list_arg->count < 1)
    {
      print_error_opt(arg);
      return (-1);
    }
  else if (arg->count_arg != -1 && arg->count_arg != arg->list_arg->count)
    {
      print_error_opt(arg);
      return (-1);
    }
  else
    return (0);
}
