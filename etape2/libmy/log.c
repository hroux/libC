/*
** log.c for  in /home/hugues/Documents/C/lib/roux_a
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Wed Feb  8 21:54:22 2017 ROUX Hugues
** Last update Sun Feb 12 16:00:55 2017 ROUX Hugues
*/

#include	"libmy.h"
#include	"log.h"
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>

static	char *msg_log[] =
  {
    "[DEBUG]",
    "[INFO]",
    "[WARNING]",
    "[ERROR]"
  };

void	print_log(int lvl, char *msg)
{
  int	file_dest;
  int	size;

  if (logger == NULL)
    return;
  if (lvl < DEBUG || lvl > ERROR)
    lvl = 0;
  if (lvl < logger->lvl)
    return;
  size = my_strlen(msg_log[lvl]);
  file_dest = logger->handle;
  if (file_dest < 0)
    return;
  if (write(file_dest, msg_log[lvl], size) != size)
    return;
  if (msg != NULL)
    {
      size = my_strlen(msg);
      if (write(file_dest, msg, size) != size)
	return;
    }
  if (write(file_dest, "\n", 1) != 1)
    return;
}

t_log		*init_log(int lvl, char *file)
{
  int		handle;
  mode_t	mode;

  mode = S_IRUSR | S_IWUSR | S_IROTH;
  logger = malloc(sizeof(t_log));
  if (logger == NULL)
    return NULL;
  logger->lvl = lvl;
  if (file == NULL)
    file = my_strdup("./journal.log");
  if (file == NULL)
    {
      free(logger);
      logger = NULL;
      return NULL;
    }
  handle = open(file, O_WRONLY | O_APPEND | O_CREAT, mode);
  free(file);
  logger->handle = handle;
  logger->info = &print_log;
  return logger;
}

void	deinit_log()
{
  if (logger == NULL)
    return;
  if (logger->handle >= 0)
    close(logger->handle);
  free(logger);
  logger = NULL;
}
