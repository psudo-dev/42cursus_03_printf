# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 16:36:06 by rsetoue           #+#    #+#              #
#    Updated: 2021/11/20 16:05:01 by rsetoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a
PRINTF_H =			ft_printf.h
LIBFT_H =			libft.h
MAKE :=				@make
CC :=				@clang
CFLAGS :=			-Wall -Wextra -Werror
AR :=				@ar -rcs
RANLIB :=			@ranlib
RM :=				@rm -f
ROOT =				.
SRC =				*.c
OBJ =				*.o

${NAME}:
	${MSG} ${FG_LAV} "Building Tests" ${RESET}
	${MSG} ${FG_GREY} "Copying ${PRINTF_H}" ${RESET} ${NO_NL}
	@cp ../inc/${PRINTF_H} ${ROOT}
	${DONE}
	${MSG} ${FG_GREY} "Copying ${LIBFT_H}" ${RESET} ${NO_NL}
	@cp ../lib/libft/inc/${LIBFT_H} ${ROOT}
	${DONE}
	${MSG} ${FG_GREY} "Copying ft_printf files" ${RESET} ${NO_NL}
	@cp ../src/${SRC} ${ROOT}
	${DONE}
	${MSG} ${FG_GREY} "Copying libft files" ${RESET} ${NO_NL}
	@cp ../lib/libft/src/${SRC} ${ROOT}
	${DONE}
	${MSG} ${FG_YELLOW} "Compiling files" ${RESET} ${NO_NL}
	${CC} ${CFLAGS} -c -I${ROOT} ${SRC}
	${DONE}
	${MSG} ${FG_YELLOW} "Building Static Library" ${RESET} ${NO_NL}
	${AR} ${NAME} ${OBJ}
	${DONE}
	${MSG} ${FG_GREY} "Indexing Library" ${RESET} ${NO_NL}
	${RANLIB} ${NAME}
	${DONE}
	${MSG} ${FG_BLUE} "Removing source files" ${RESET} ${NO_NL}
	${RM} ${SRC}
	${DONE}
	${MSG} ${FG_BLUE} "Removing object files" ${RESET} ${NO_NL}
	${RM} ${OBJ}
	${DONE}
	${MSG} ${FG_GREEN} "Finished!" ${RESET}

all: ${NAME}

bonus: all

clean:
	${MSG} ${FG_BLUE} "Source files and Object files removed" ${RESET} \
	${FG_GREEN} "✔" ${RESET}

fclean: clean
	${MSG} ${FG_BLUE} "Removing header files" ${RESET} ${NO_NL}
	${RM} *.h
	${DONE}
	${MSG} ${FG_BLUE} "Removing ${NAME}" ${RESET} ${NO_NL}
	${RM} libftprintf.a
	${DONE}

re: rebuilding_msg fclean all

rebuilding_msg:
	${MSG} ${FG_LAV} "Rebuilding Tests" ${RESET}

.PHONY: all clean fclean

# ? Messages
FG_GREEN =			"\033[38;2;73;242;73m"
FG_BLUE =			"\033[38;2;80;182;255m"
FG_YELLOW =			"\033[38;2;230;230;72m"
FG_GREY =			"\033[38;2;144;150;160m"
FG_PINK =			"\033[38;2;255;102;204m"
FG_LAV =			"\033[38;2;170;128;255m"
FG_ORANGE =			"\033[38;2;255;167;64m"

MSG =				@echo
RESET =				"\033[0m"
NO_NL :=			| tr -d '\n'
DONE :=				${MSG} ${FG_GREEN} "✔" ${RESET}

# :					"code[
# ~					48;2 (background color)
# ~					38;2 (foreground color)
# >					;R;G;B
# <					m
# ?					\033[0m" (reset)
