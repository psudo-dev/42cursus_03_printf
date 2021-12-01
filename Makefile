# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsetoue <rsetouestudent.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 20:40:41 by rsetoue           #+#    #+#              #
#    Updated: 2021/10/03 23:44:08 by rsetoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=				libftprintf.a
PRINTF :=			ft_printf
LIBFT :=			libft

BIN_DIR :=			bin
LIB_DIR :=			lib
SRC_DIR :=			src
OBJ_DIR :=			build
INC_DIR :=			inc
TEST_DIR :=			test
ALL_DIR :=			${BIN_DIR} \
					${LIB_DIR} \
					${SRC_DIR} \
					${OBJ_DIR} \
					${INC_DIR}

SRC_FILES :=		ft_printf.c \
					flags.c \
					specifiers.c \
					precision.c \
					printers.c \
					structs.c \
					type_char.c \
					type_int.c \
					type_hex.c \
					utils.c \
					width.c

SRC :=				${addprefix ${SRC_DIR}/,${SRC_FILES}}
OBJ :=				${addprefix ${OBJ_DIR}/,${SRC_FILES:.c=.o}}

PRINTF_H :=			${INC_DIR}/${PRINTF}.h
LIBFTPRINTF_A :=	${BIN_DIR}/${NAME}

LIBFT_DIR :=		${LIB_DIR}/${LIBFT}
LIBFT_SRC :=		${LIBFT_DIR}/${SRC_DIR}
LIBFT_H :=			${LIBFT_DIR}/${INC_DIR}/${LIBFT}.h
LIBFT_A :=			${LIBFT_DIR}/${BIN_DIR}/${LIBFT}.a
LIBFT_FILES :=		${addprefix ${LIBFT_SRC}/,*.c}

# with -I flags showing the headers dir, it's possible to use
# #include <header.h> in all .c files
INCLUDE :=			-I${LIBFT_DIR}/${INC_DIR} -I${INC_DIR}

MAKE :=				@make
CC :=				@clang
CFLAGS :=			-Wall -Wextra -Werror
AR :=				@ar -rcs
RANLIB :=			@ranlib
RM_FILE :=			@rm -f
RM_FOLDER :=		@rm -rf

# < RECIPES
${NAME}: ${ALL_DIR} ${LIBFT_A} ${OBJ}
	${MSG_COMPILING}
	${AR} ${NAME} ${OBJ}
	${DONE}
	${MSG_INDEX_LIB}
	${RANLIB} ${NAME}
	${DONE}
	@cp -f ${NAME} ${BIN_DIR}
	${MSG_FINISHED}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${PRINTF_H}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

# copy libft.a as libftprintf.a
${LIBFT_A}: ${LIBFT_H} ${LIBFT_FILES}
	${MAKE} -C ${LIBFT_DIR}
	${MSG_BUILD_LIB}
	${MSG_COPY_LIB}
	@cp ${LIBFT_A} ${NAME}
	${DONE}

${ALL_DIR}:
	${MSG_BUILDING}
	${MSG_CREATE_DIR}
	@mkdir -p ${ALL_DIR}
	${DONE}

all: ${NAME}

bonus: all

clean: clean_libft clean_build
	${MSG_FINISHED}

fclean: fclean_libft clean_build clean_program
	${MSG_RM_EMPTY_DIR}
	${RM_FILE} ${INC_DIR}/${LIBFT}.h
	${DONE}

re: msg_rebuilding fclean all

retest: rebuild_test

# : CLEANING
clean_build: msg_cleaning
	${RM_FILE} ${OBJ}
	${DONE}

clean_program: msg_fcleaning
	${RM_FILE} ${LIBFTPRINTF_A} ${NAME}
	${DONE}

clean_libft:
	${MAKE} clean -C ${LIBFT_DIR}

fclean_libft:
	${MAKE} fclean -C ${LIBFT_DIR}

# ? TEST

# : creates Makefile and copy from Macro content
# : sed eliminates leading/trailing whitespaces
# : since newline let a leading space

TRIPOUILLE_DIR :=	${TEST_DIR}/tripouille
PSANTANA_DIR :=		${TEST_DIR}/psantana

TEST_FILES =		${TEST_DIR}/libftprintf.a \
					${TEST_DIR}/ft_printf.h \
					${TEST_DIR}/libft.h \

${PSANTANA_DIR}:
	@git clone \
	https://github.com/paulo-santana/ft_printf_tester.git \
	${PSANTANA_DIR}
	${MSG_FINISHED}

${TRIPOUILLE_DIR}:
	@git clone \
	https://github.com/Tripouille/printfTester.git \
	${TRIPOUILLE_DIR}
	${MSG_FINISHED}

test: ${PSANTANA_DIR} ${TRIPOUILLE_DIR}
	${MAKE} -C ${TEST_DIR}
t: test

mandatory_tests: test
	${MSG} ${FG_LAV} "running psantana tests: MANDATORY" ${RESET}
	cd ${PSANTANA_DIR}; sh test m; cd ..;
	${MSG} ${FG_LAV} "running tripouille tests: MANDATORY" ${RESET}
	${MAKE} m -C ${TRIPOUILLE_DIR}
m: mandatory_tests

bonus_tests: ${PSANTANA_DIR} ${TRIPOUILLE_DIR}
	${MSG} ${FG_LAV} "running psantana tests: BONUS" ${RESET}
	@cd ${PSANTANA_DIR}; sh test b1; cd ..;
	@cd ${PSANTANA_DIR}; sh test b2; cd ..;
	${MSG} ${FG_LAV} "running tripouille tests: BONUS" ${RESET}
	${MAKE} b -C ${TRIPOUILLE_DIR}
b: bonus_tests

all_tests: ${PSANTANA_DIR} ${TRIPOUILLE_DIR}
	${MSG} ${FG_LAV} "running psantana tests: ALL" ${RESET}
	@cd ${PSANTANA_DIR}; sh test; cd ..;
	${MSG} ${FG_LAV} "running tripouille tests: ALL" ${RESET}
	${MAKE} a -C ${TRIPOUILLE_DIR}
a: all_tests

clean_test:
	${MSG} ${FG_PINK} "make clean_test tests" ${RESET}
	${MAKE} clean -C ${TEST_DIR}
c: clean_test

fclean_test:
	${MSG} ${FG_PINK} "make fclean_test tests" ${RESET}
	${MAKE} fclean -C ${TEST_DIR}
f: fclean_test

rebuild_test:
	${MSG} ${FG_PINK} "make rebuild_test tests" ${RESET}
	${MAKE} re -C ${TEST_DIR}
	${MSG_FINISHED}
r: rebuild_test

delete_test: fclean_test
	${MSG} ${FG_PINK} "Removing ${PSANTANA_DIR} Folder" ${RESET} ${NO_NL}
	${RM_FOLDER} ${PSANTANA_DIR}
	${DONE}
	${MSG} ${FG_PINK} "Removing ${TRIPOUILLE_DIR} Folder" ${RESET} ${NO_NL}
	${RM_FOLDER} ${TRIPOUILLE_DIR}
	${DONE}
	${MSG_FINISHED}
d: delete_test

exit: fclean delete_test
e: exit

.PHONY: all test clean fclean re

# ~ MESSAGES
FG_GREEN :=			"\033[38;2;73;242;73m"
FG_BLUE :=			"\033[38;2;80;182;255m"
FG_YELLOW :=		"\033[38;2;230;230;72m"
FG_GREY :=			"\033[38;2;144;150;160m"
FG_PINK :=			"\033[38;2;255;102;204m"
FG_LAV :=			"\033[38;2;170;128;255m"
FG_ORANGE :=		"\033[38;2;255;167;64m"

MSG :=				@echo
RESET :=			"\033[0m"
NO_NL :=			| tr -d '\n'
DONE :=				${MSG} ${FG_GREEN} "✔" ${RESET}

# : 				"code[
# ~ 				48;2 (background color)
# ~ 				38;2 (foreground color)
# > 				;R;G;B
# < 				m
# ? 				\033[0m" (reset)

MSG_INDEX_LIB =		${MSG} ${FG_GREY} "Indexing ${PRINTF} library..." \
					${RESET} ${NO_NL}
MSG_BUILD_LIB =		${MSG} ${FG_YELLOW} "Building ${PRINTF} library..." \
					${RESET}
MSG_COPY_LIB =		${MSG} ${FG_GREY} "Copying Libft Library to Printf..." \
					${RESET} ${NO_NL}
MSG_COMPILING =		${MSG} ${FG_YELLOW} "Compiling ${PRINTF}..." \
					${RESET} ${NO_NL}
msg_compiling:
	${MSG_COMPILING}
MSG_BUILDING =		${MSG} ${FG_ORANGE} "Building ${PRINTF} files..." \
					${RESET}
msg_building:
	${MSG_BUILDING}
MSG_REBUILDING =	${MSG} ${FG_PINK} "Rebuilding executable..." \
					${RESET}
msg_rebuilding:
	${MSG_REBUILDING}
MSG_CLEANING =		${MSG} ${FG_BLUE} "Cleaning ${PRINTF} Build..." \
					${RESET} ${NO_NL}
msg_cleaning:
	${MSG_CLEANING}
MSG_FCLEANING =		${MSG} ${FG_BLUE} "Cleaning ${PRINTF} Program..." \
					${RESET} ${NO_NL}
msg_fcleaning:
	${MSG_FCLEANING}
MSG_CREATE_DIR =	${MSG} ${FG_GREY} "Creating Project Folders..." \
					${RESET} ${NO_NL}
msg_create_dir:
	${MSG_CREATE_DIR}
MSG_RM_EMPTY_DIR =	${MSG} ${FG_PINK} "Removing Empty Folders" \
					${RESET} ${NO_NL}
msg_rm_empty_dir:
	${MSG_RM_EMPTY_DIR}
MSG_FINISHED	=	${MSG} ${FG_GREEN} "Finished!" \
					${RESET}
msg_finished:
	${MSG_FINISHED}

done:
	${DONE}
