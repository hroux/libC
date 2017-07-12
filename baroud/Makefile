##
## Makefile for  in /home/hugues/DEVC/CHIFUMI/roux_a/chifumi
## 
## Made by ROUX Hugues
## Login   <roux_a@etna-alternance.net>
## 
## Started on  Thu Dec  1 23:12:53 2016 ROUX Hugues
## Last update Tue Feb 21 22:59:38 2017 ROUX Hugues
##

CC		=	gcc

LIB_DIR		=	libmy

NAME_LIB	=	libmy.a

NAME		=	baroud

SRC		=	main.c \
			baroud.c \
			cpy.c

OBJS		=	$(SRC:%.c=%.o)

RM		=	rm -rf

CFLAGS		=	-lpthread -Wall -Werror -Wextra -L.

LDFLAGS		=	-lmy

EXEC		=	$(MAKE) -C

all		:	lib $(NAME)

lib		:
			$(EXEC) $(LIB_DIR)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean		:
			$(RM) $(OBJS)
			$(EXEC) $(LIB_DIR) clean

fclean		:	clean
			$(RM) $(NAME)
			$(EXEC) $(LIB_DIR) fclean

.PHONY		:	clean fclean

re		:	fclean all
