/*
** libList.h for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 22:42:33 2017 ROUX Hugues
** Last update Sun Jan 29 22:49:25 2017 ROUX Hugues
*/

#ifndef			_LIST_H_
# define	       	_LIST_H_

typedef struct 		s_chain
{
  int	       		index;
  void		       	*data;
  struct s_chain	*next;
  struct s_chain	*prev;
}			t_chain;
typedef struct		s_list
{
  struct s_chain	*head;
  int		       	count;
  int			(*compare)();
}	       		t_list;

t_list			*init_list(int (*comp)());
int			add_list(t_list *list, t_chain *chain);
t_chain			*init_chain(void *data);
t_chain			*search_ind(t_list *list, int ind);
t_chain			*search_val(t_list *list, void *data);
int			del_list(t_list *list, t_chain *chain);
int			deinit_list(t_list *list);

#endif			/*_LIST_H_*/
