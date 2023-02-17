# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 22:06:42 by seozkan           #+#    #+#              #
#    Updated: 2023/02/17 22:49:28 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror
BONUS_NAME = checker

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/check.c \
		srcs/push_swap/find.c \
		srcs/push_swap/operations_three.c \
		srcs/push_swap/operations_two.c \
		srcs/push_swap/operations.c \
		srcs/push_swap/rotate_and_push.c \
		srcs/push_swap/rotate_type.c \
		srcs/push_swap/solver_utils.c \
		srcs/push_swap/sort.c \
		srcs/push_swap/stack_utils.c \
		srcs/push_swap/utils_two.c \
		srcs/push_swap/utils.c \
		srcs/push_swap/split.c
		
BONUS_SRC = srcs/checker/checker.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o} -g

${NAME}: ${OBJ_1} ${OBJ_2}
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME}
	@echo "\n\033[33mMandatory files compiled successfully ✅\033[0m\n"
${BONUS_NAME}: ${OBJ_2} ${BONUS_OBJ} 
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS_NAME}

all: ${NAME} ${BONUS_NAME}

bonus: ${BONUS_NAME} 
	@echo "\n\033[33mBonus files compiled successfully ✅\033[0m\n"
clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ}
	@echo "\n\033[33mObject files compiled successfully ✅\033[0m\n"

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}
	@echo "\n\033[33mAll files deleted successfully ✅\033[0m\n"

re: clean all

.PHONY: all clean fclean re bonus
