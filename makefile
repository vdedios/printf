# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/01/21 13:41:13 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	 libftprintf.a
LIBFT 	=	libft.a

LIB_DIR 	= 	libft/

CC	=	 gcc

CFLAGS	=	 -Werror -Wall -Wextra

AR	=	 ar -rcs

SRC	=		flags.c				\
			printf.c			\
			thousands_utils.c	\
			types_cspdiu.c		\
			types_xXfegn.c		\
			utils_e.c			\
			utils_f.c			\
			utils_format.c		\
			utils_g.c			\
			utils_printf.c		\
			utils_xXp.c			\
			width_precision.c	

BONUS	=	flags_bonus.c			\
			printf_bonus.c			\
			thousands_utils_bonus.c	\
			types_cspdiu_bonus.c	\
			types_xXfegn_bonus.c	\
			utils_e_bonus.c			\
			utils_f_bonus.c			\
			utils_format_bonus.c	\
			utils_g_bonus.c			\
			utils_printf_bonus.c	\
			utils_xXp_bonus.c		\
			width_precision_bonus.c	

OBJS	 =	$(SRC:%.c=%.o)

OBJ_BONUS=	$(BONUS:%.c=%.o)

all	:	$(NAME)

$(NAME)	: 	$(OBJS) printf.h
		@echo Loading libft ...⏳
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
		@echo buildind everyhing ...🔨
		@$(AR) $(NAME) $(OBJS)
		@echo done, like a boss 😎

%.o	:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

bonus	:	$(OBJS) $(OBJ_BONUS) printf.h
	@$(AR) $(NAME) $(OBJ_BONUS) $(OBJS)

clean	:
	@echo Cleaning ...🧼
	@@@rm -rf $(OBJS) $(OBJ_BONUS)
	@make -C $(LIB_DIR) clean
	@echo everything cleaned and shiny 🗑

fclean	: 	clean
	@rm -rf $(NAME)

re	:	fclean all
	@echo Now you can reach the stars 🚀

.PHONY: clean fclean all re bonus
