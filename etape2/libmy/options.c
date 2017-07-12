/*
** parsing.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Jan 25 16:32:32 2017 ROUX Hugues
** Last update Wed Feb 22 22:21:57 2017 ROUX Hugues
*/

#include	<stdlib.h>
#include	"libmy.h"
#include	"list.h"
#include	"parse.h"

t_parsing	*search_option(t_arg *arg, char *opt)
{
  t_chain	*chain;

  if (opt == NULL || arg == NULL)
    return (NULL);
  chain = search_val(arg->list_opt, opt);
  if (chain == NULL)
    return (NULL);
  return (chain->data);
}

int		do_fnc_opt(t_arg *arg)
{
  t_chain	*chain;
  t_parsing	*parse;
  int		i;

  if (arg == NULL)
    return (1);
  if (arg->list_opt == NULL)
    return (0);
  chain = arg->list_opt->head;
  i = 0;
  while (i != arg->list_opt->count)
    {
      parse = chain->data;
      if (parse != NULL)
	parse->do_fnc(parse->defaut, arg->list_arg);
      chain = chain->next;
      i++;
    }
  return (0);
}

int		add_arg(t_arg *arg, char *str)
{
  t_chain	*chain;

  if (arg == NULL)
    return (-1);
  chain = init_chain(str);
  if (chain == NULL || arg == NULL)
    return (-1);
  return (add_list(arg->list_arg, chain));   
}

int		init_option(t_arg *arg, char **argv)
{
  t_parsing	*parse;

  if (arg == NULL)
    return (1);
  while (argv != NULL && *argv != NULL)
    {
      if (**argv == '-')
	{
	  if ((parse = search_option(arg, *argv)) == NULL)
	    return (-1);
	  if (*(argv + 1) == NULL)
	    return (0);
	  if (**(argv + 1) != '-')
	    {
	      free(parse->defaut);
	      parse->defaut = my_strdup(*(argv + 1));
	      argv++;
	    }
	}
      else
	if (add_arg(arg, my_strdup(*argv)) != 0)
	  return (-1);
      argv++;
    }
  return (0);
}

int		my_arg_compare(t_parsing *parsing, char *s2)
{
  char		*save;

  if (parsing == NULL)
    return (-1);
  save = parsing->opt;
  if (save == NULL && s2 != NULL)
    return (-1);
  if (s2 == NULL && save != NULL)
    return (1);
  if (s2 == NULL && save == NULL)
    return (0);
  while (*save != '\0' && *s2 != '\0')
    {
      if (*save < *s2)
	return (-1);
      if (*save > *s2)
	return (1);
      save = save + 1;
      s2 = s2 + 1;
      if (*save == '\0' && *s2 != '\0')
	return (-1);
      if (*s2 == '\0' && *save != '\0')
	return (1);
    }
  return (0);
}
