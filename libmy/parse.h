/*
** parse.h for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sun Jan 15 21:54:51 2017 ROUX Hugues
** Last update Sun Jan 29 18:22:18 2017 ROUX Hugues
*/

#ifndef _PARSE_H_
# define _PARSE_H_

typedef struct	s_parsing
{
  char		*opt;
  void		(*do_fnc)(char *str);
  char		*help;
  void		*defaut;
}		t_parsing;
typedef struct	s_arg
{
  t_list	*list_opt;
  int		count_arg;
  t_list	*list_arg;
}		t_arg;

t_parsing	*init_pars(char *opt, void (*do_fnc)(),
			   char *help, void *defaut);
t_arg		*init_arg(int count_arg, t_list *list);
void		deinit_arg(t_arg *arg);
void		print_error_opt(t_arg *arg);
int		check_arg_opt(t_arg *arg, char **argv);
t_parsing	*search_option(t_arg *arg, char *opt);
int		do_fnc_opt(t_arg *arg);
int		add_arg(t_arg *arg, char *str);
int		init_option(t_arg *arg, char **argv);
int		my_arg_compare(t_parsing *parsing, char *s2);

#endif		/*_PARSE_H_*/
