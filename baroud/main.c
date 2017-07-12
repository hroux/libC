/*
** main.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 22:09:17 2017 ROUX Hugues
** Last update Wed Feb 22 22:38:06 2017 ROUX Hugues
*/

#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	"libmy/parse.h"
#include	"libmy/log.h"
#include	"cpy.h"
#include	<stdlib.h>

t_log		*logger;

int		main(int argc, char **argv)
{
  t_list	*list;
  t_arg		*arg;
  t_parsing	*parse;
  t_chain	*chain;

  logger = init_log(DEBUG, my_strdup("journal.log"));
  list = init_list(&my_arg_compare);
  parse = init_pars("--dest", &my_cpy_list,
		    "Fichier de destination", my_strdup("."));
  chain = init_chain(parse);
  add_list(list, chain);
  arg = init_arg(-1, list);
  check_arg_opt(arg, argv + 1);
  do_fnc_opt(arg);
  if (argc == 0)
    my_putstr("\n");
  deinit_arg(arg);
  deinit_log();
  return (0);
}
