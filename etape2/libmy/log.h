/*
** log.h for  in /home/hugues/Documents/C/lib/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Feb  8 21:56:13 2017 ROUX Hugues
** Last update Sun Feb 12 16:12:29 2017 ROUX Hugues
*/

#ifndef		_LOG_H_
# define	_LOG_H_

# define	DEBUG		0
# define	INFO		1
# define	WARNING		2
# define	ERROR		3

typedef struct	s_log
{
  int		lvl;
  void		(*info)(int lvl, char *msg);
  int		handle;
}		t_log;

extern t_log	*logger;

t_log		*init_log(int lvl, char *file);
void		deinit_log();

#endif		/*_LOG_H_*/
