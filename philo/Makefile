# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 10:22:01 by matde-ol          #+#    #+#              #
#    Updated: 2024/04/06 12:09:58 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

DIR_SRC = src/
DIR_OBJ = obj/

FLAGS = -Werror -Wextra -Wall

SRC = \
		action_philo.c \
		philo_meals.c \
		take_forks.c \
		check_arg.c \
		check_life_philo.c \
		clear.c \
		philo_create.c \
		print.c \
		routine.c \
		utils.c \
		start_simulation.c \
		main.c

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
	rm -f $(NAME)

re : clean all

.PHONY: all clean fclean re
