/*
** cpy.c for  in /home/hugues/Documents/C/lib/roux_a/baroud
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Tue Feb 21 20:56:02 2017 ROUX Hugues
** Last update Wed Feb 22 22:39:08 2017 ROUX Hugues
*/

#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	"libmy/log.h"
#include	"cpy.h"
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>

static char	*tab_error[] =
  {
    "La copie est terminée",
    "Ouverture du fichier source impossible",
    "Ouverture ou création du fichier de destination impossible",
    "Erreur lecture du fichier source",
    "Erreur écriture du fichier de destination"
  };

void	print_error_cpy(int	i)
{
  if (i > 5 || logger == NULL)
    return;
  if (i == 0)
    logger->info(INFO, tab_error[i]);
  else
    logger->info(WARNING, tab_error[i]);
}

char		*my_read(int handle)
{
  char		*buff;
  ssize_t	ret;

  if ((buff = malloc(sizeof(*buff) * 51)) == NULL)
    return (NULL);
  if ((ret = read(handle, buff, 50)) > 1)
    {
      buff[ret] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return(buff);
}

int		my_cpy(t_cpy *cpy)
{
  int		handle_src;
  int		handle_dest;
  char		*buff;
  mode_t	mode;

  if (cpy == NULL)
    return (1);
  mode = S_IRUSR | S_IWUSR | S_IROTH;
  if ((handle_src = open(cpy->file_cpy, O_RDONLY)) < 0)
    return (1);
  if ((handle_dest = open(cpy->file_dest, O_WRONLY | O_CREAT, mode)) < 0)
    return (2);
  if ((buff = my_read(handle_src)) == NULL)
    return (3);
  while (my_strlen(buff) != 0)
    {
      if((write(handle_dest, buff, my_strlen(buff))) == -1)
	return (4);
      free(buff);
      buff = my_read(handle_src);
    }
  free(buff);
  close(handle_src);
  close(handle_dest);
  return (0);
}

void	deinit_cpy(t_cpy *cpy)
{
  if (cpy == NULL)
    return;
  if (cpy->file_dest != NULL)
    free(cpy->file_dest);
  if (cpy->file_cpy != NULL)
    free(cpy->file_cpy);
  free(cpy);
}

t_cpy	*init_cpy(char *file_dest, char *file_cpy)
{
  t_cpy	*cpy;
  char	*temp;

  if (file_dest == NULL || file_cpy == NULL)
    return (NULL);
  cpy = malloc(sizeof(t_cpy));
  if (cpy == NULL)
    return (NULL);
  temp = my_strdup(file_dest);
  if (temp == NULL)
    {
      free(cpy);
      return (NULL);
    }
  cpy->file_dest = temp;
  temp = my_strdup(file_cpy);
  if (temp == NULL)
    {
      free(cpy->file_dest);
      free(cpy);
      return (NULL);
    }
  cpy->file_cpy = temp;
  return (cpy);
}
