# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 10:22:01 by matde-ol          #+#    #+#              #
#    Updated: 2024/02/19 16:32:48 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

DIR_SRC = src/
DIR_OBJ = obj/

FLAGS = -Werror -Wextra -Wall -g

SRC = \
		action_philo.c \
		check_arg.c \
		check_life_philo.c \
		clear.c \
		philo_create.c \
		print.c \
		simulation.c \
		utils.c \
		main.c \
		fichier_a_suppr.c

OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@
	
$(DIR_OBJ)%.o : $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(FLAGS) -c $< -o $@
		
fclean : clean
	make -C $(DIR_OBJ) fclean
	rm -f $(NAME)
clean :
	rm -rf $(DIR_OBJ) clean

re : clean all

.PHONY: all clean fclean re
