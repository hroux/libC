/*
** baroud.c for  in /home/hugues/Documents/C/lib/roux_a/baroud
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Sun Feb 12 18:36:06 2017 ROUX Hugues
** Last update Wed Feb 22 22:39:42 2017 ROUX Hugues
*/

#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	"libmy/log.h"
#include	"cpy.h"
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>

t_log		*logger = NULL;

char		*get_name(char *name_file, char *name_arg)
{
  int		size;
  char       	*name_file_to_cpy;
  char		*temp;

  size = my_strlen(name_file) + my_strlen(name_arg) + 2;
  name_file_to_cpy = malloc(sizeof(char) * size);
  if (name_file_to_cpy == NULL)
    return (NULL);
  name_file_to_cpy[0] = '\0';
  my_strcpy(name_file_to_cpy, name_file);
  size = my_strlen(name_file_to_cpy);
  temp = my_strdup("/");
  if (temp != NULL)
    {
      my_strcpy(&(name_file_to_cpy[size]), temp);
      free(temp);
    }
  size = my_strlen(name_file_to_cpy);
  my_strcpy(&(name_file_to_cpy[size]), name_arg);
  return name_file_to_cpy;
}

void		my_cpy_list(char *file_dest, t_list *list_arg)
{
  char		*name_file;
  char		*name_file_to_cpy;
  t_chain	*chain;
  t_cpy		*cpy;

  while (list_arg->head != NULL)
    {
      chain = list_arg->head;
      name_file = chain->data;
      name_file_to_cpy = get_name(file_dest, name_file);
      if ((cpy = init_cpy(name_file_to_cpy, name_file)) == NULL)
	return;
      if (logger != NULL)
	{
	  logger->info(INFO, name_file);
	  logger->info(INFO, "Commencement copie");
	}
      print_error_cpy(my_cpy(cpy));
      free(name_file_to_cpy);
      del_list(list_arg, chain);
      deinit_cpy(cpy);
    }
}
