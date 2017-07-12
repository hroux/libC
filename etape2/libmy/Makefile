##
## Makefile for  in /home/hugues/Documents/C/lib/libmy
## 
## Made by ROUX Hugues
## Login   <roux_a@etna-alternance.net>
## 
## Started on  Sun Jan 29 16:06:57 2017 ROUX Hugues
## Last update Sun Feb 12 21:23:17 2017 ROUX Hugues
##

AR		=	ar r

ARCH_LIB	=	ranlib

NAME		=	../libmy.a

SRC		=	my_putstr.c \
			my_putchar.c \
			list_init.c \
			list_deinit.c \
			list_search.c \
			my_strdup.c \
			my_strcpy.c \
			my_strlen.c \
			my_strcmp.c \
			init_parsing.c \
			options.c \
			parsing_error.c \
			my_put_nbr.c \
			log.c \
			my_strncpy.c \
			my_strcpy.c

OBJS		=	$(SRC:%.c=%.o)

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(ARCH_LIB) $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

.PHONY		:	clean fclean

re		:	fclean all
