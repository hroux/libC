##
## Makefile for  in /home/hugues/DEVC/CHIFUMI/roux_a/chifumi
## 
## Made by ROUX Hugues
## Login   <roux_a@etna-alternance.net>
## 
## Started on  Thu Dec  1 23:12:53 2016 ROUX Hugues
## Last update Sun Feb 12 14:21:15 2017 ROUX Hugues
##

CC		=	gcc

LIB_DIR		=	libmy

NAME_LIB	=	libmy.a

NAME		=	a.out

SRC		=	main.c \

OBJS		=	$(SRC:%.c=%.o)

RM		=	rm -rf

CFLAGS		=	-Wall -Werror -Wextra -L.

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
