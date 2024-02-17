# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 10:22:01 by matde-ol          #+#    #+#              #
#    Updated: 2024/02/17 10:22:19 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

DIR_SRC = src/
DIR_OBJ = obj/

FLAGS = -Werror -Wextra -Wall -g

SRC = \
		 actions.c \
		 check_arg.c \
		 init_data.c \
		 philo.c \
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
