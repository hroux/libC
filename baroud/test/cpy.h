/*
** baroud.h for  in /home/hugues/Documents/C/lib/roux_a/baroud
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sat Feb 18 15:11:32 2017 ROUX Hugues
** Last update Wed Feb 22 22:37:25 2017 ROUX Hugues
*/

#ifndef		_BAROUD_H_
# define	_BAROUD_H_

typedef struct 	s_cpy
{
  char		*file_dest;
  char		*file_cpy;
}		t_cpy;

t_cpy		*init_cpy(char *file_dest, char *file_cpy);
void		deinit_cpy(t_cpy *cpy);
int		my_cpy(t_cpy *cpy);
void		print_error_cpy(int i);
char		*my_read(int handle);
void		my_cpy_list(char *file_dest, t_list *list_arg);

#endif		/*_BAROUD_H_*/
