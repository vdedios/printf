# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:19:32 by vde-dios          #+#    #+#              #
#    Updated: 2020/01/23 12:46:57 by vde-dios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT 	=	libft.a

LIB_DIR 	= 	libft/
OBJ_DIR 	=	obj/
SRC_DIR 	= 	src/
BONUS_DIR 	= 	src_bonus/
HEAD_DIR	=	header/

CC	=	gcc

FLAGS	= -Werror -Wall -Wextra
LFLAGS	= -I header/

AR	=	 ar -rcs

SRC_FILES	=		flags.c		\
			printf.c			\
			types_cspdiu.c		\
			types_hexfegn.c		\
			utils_format.c		\
			utils_printf.c		\
			utils_hexp.c		\
			width_precision.c	

BONUS_FILES	=	thousands_utils_bonus.c		\
			utils_e_bonus.c					\
			utils_f_bonus.c					\
			utils_g_bonus.c					\

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

OBJ_BONUS_FILES	=	$(BONUS_FILES:%.c=%.o)
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_BONUS_FILES))

all	:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Created printf Object directory 📌

$(NAME)	: 	$(OBJ_FILES)
		@echo Loading libft ...⏳
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
		@echo buildind basic functions ...🔨
		@$(AR) $(NAME) $(OBJ)
		@echo done, like a boss 😎

$(OBJ_FILES):
		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

$(OBJ_BONUS_FILES):
		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(BONUS_DIR)$(@:%.o=%.c)

bonus	:	all $(OBJ_BONUS_FILES)
	@echo buildind bonus functions ...🌟
	@$(AR) $(NAME) $(OBJ_BONUS) $(OBJ)
	@echo success!!🍾

clean	:
	@echo Cleaning ...🧼
	@@@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo everything cleaned and shiny 🗑

fclean	: 	clean
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean
	@rm -rf $(LIBFT)

re	:	fclean all
	@echo Now you can reach the stars 🚀

.PHONY: clean fclean all re bonus
