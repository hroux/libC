/*
** main.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 22:09:17 2017 ROUX Hugues
** Last update Wed Feb 22 22:25:21 2017 ROUX Hugues
*/

#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	"libmy/parse.h"
#include	<stdlib.h>

/**
 * Test flot normal
 **/
void		test1(char **argv)
{
  t_list	*list;
  t_arg		*arg;
  t_chain	*chain;
  t_parsing	*parse;

  list = init_list(&my_arg_compare);
  parse = init_pars("-t", &my_putstr, "Option de test", my_strdup("def\n"));
  chain = init_chain(parse);
  add_list(list, chain);
  parse = init_pars("-i", &my_putstr, "Option de test2", my_strdup("def2\n"));
  chain = init_chain(parse);
  add_list(list, chain);
  arg = init_arg(-1, list);
  check_arg_opt(arg, argv + 1);
  do_fnc_opt(arg);
  deinit_arg(arg);
}

/**
 * Sans options
 **/
void		test2(char **argv)
{
  t_list	*list;
  t_arg		*arg;

  list = init_list(&my_arg_compare);
  arg = init_arg(-1, list);
  check_arg_opt(arg, argv);
  do_fnc_opt(arg);
  deinit_arg(arg);
}

/**
 *Test unitaire
 *
 **/
void		test3()
{
  t_arg		*arg;
  t_parsing	*parsing;
  
  parsing = init_pars(NULL, NULL, NULL, NULL);
  if (parsing != NULL)
    {
      free(parsing->opt);
      free(parsing);
    }
  arg = init_arg(0, NULL);
  if (arg != NULL)
    deinit_arg(arg);
  check_arg_opt(NULL, NULL);
  print_error_opt(NULL);
  search_option(NULL, NULL);
  add_arg(NULL, NULL);
  my_arg_compare(NULL, NULL);
  do_fnc_opt(NULL);
  deinit_arg(NULL);
}

int		main(int argc, char **argv)
{
  my_putstr("Test 1 :\n");
  test1(argv);
  my_putstr("Test 2 : \n");
  test2(argv);
  my_putstr("Test 3 : \n");
  test3();
  if (argc == 0)
    my_putstr("test");
  return (0);
}
