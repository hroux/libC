/*
** main.c for  in /home/hugues/Documents/C/lib
** 
** Made by ROUX Hugues
** Login   <roux_a@etna-alternance.net>
** 
** Started on  Mon Jan  9 22:09:17 2017 ROUX Hugues
** Last update Wed Feb 22 22:28:31 2017 ROUX Hugues
*/

#include	"libmy/libmy.h"
#include	"libmy/list.h"
#include	"libmy/log.h"
#include	<stdlib.h>

t_log		*logger = NULL;
/*
 * Test flot de base : test de la gestion des niveaux
 *
 */
void	test1()
{
  if (logger != NULL)
    {
      logger->info(DEBUG, "un log de debug");
      logger->info(INFO, "un log d'info");
      logger->info(WARNING, "un log de warning");
      logger->info(ERROR, "un log d'error");
    }
  deinit_log();
  init_log(ERROR, NULL);
  if (logger != NULL)
    {
      logger->info(DEBUG, "un log de debug");
      logger->info(INFO, "un log d'info");
      logger->info(WARNING, "un log de warning");
      logger->info(ERROR, "un log d'error");
    }
  deinit_log();
}

/*
 * Test cas d'erreur 
 *
 */
void	test2()
{
  init_log(-9, my_strdup("./test2.log"));
  if (logger != NULL)
    logger->info(DEBUG, "test2");
  deinit_log();
  logger = init_log(8, my_strdup("./test2.log"));
  if (logger != NULL)
    logger->info(DEBUG, "test2");
  deinit_log();
  init_log(INFO, my_strdup("./test2/test2.log"));
  if (logger != NULL)
    logger->info(DEBUG, "test2");
  deinit_log();
  init_log(INFO, my_strdup(""));
  if (logger != NULL)
    logger->info(DEBUG, "test2");
  deinit_log();
  init_log(INFO, my_strdup("./test2.log"));
  if (logger != NULL)
    {
      logger->info(DEBUG, NULL);
      logger->info(DEBUG, "test3");
    }
  deinit_log();
}

int	main()
{
  init_log(DEBUG, my_strdup("./testexternalisation.log"));
  test1();
  test2();
  return (0);
}
