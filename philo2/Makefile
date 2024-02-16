# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:10:49 by matde-ol          #+#    #+#              #
#    Updated: 2024/02/07 11:47:49 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

DIR_SRC = src/
DIR_OBJ = obj/

FLAGS = -Werror -Wextra -Wall

SRC = \
		actions.c \
		check_arg.c \
		init_data.c \
		philo.c \
		print_conditions.c \
		simulation.c \
		timer.c \
		utils.c
	

OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
	
$(DIR_OBJ)%.o : $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(FLAGS) -c $< -o $@
		
clean :
	rm -rf $(DIR_OBJ) clean

fclean : clean
	make -C $(DIR_OBJ) fclean
	rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re
