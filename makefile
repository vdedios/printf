# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/01/21 11:39:34 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	 libft.a

CC	=	 gcc

CFLAGS	=	 -Werror -Wall -Wextra

AR	=	 ar -rcs

SRC	=	 
BONUS	 =	 

OBJS	 =	$(SRC:%.c=%.o)

OBJ_BONUS=	$(BONUS:%.c=%.o)

all	:	$(NAME)

$(NAME)	: 	$(OBJS) libft.h
	$(AR) $(NAME) $(OBJS)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

bonus	:	$(OBJS) $(OBJ_BONUS) libft.h
	$(AR) $(NAME) $(OBJ_BONUS) $(OBJS)

clean	:
	rm -rf $(OBJS) $(OBJ_BONUS)

fclean	: 	clean
	rm -rf $(NAME)

re	:	fclean all

.PHONY: clean fclean all re bonus
