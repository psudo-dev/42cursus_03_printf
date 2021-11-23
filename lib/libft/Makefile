# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 20:40:41 by rsetoue           #+#    #+#              #
#    Updated: 2021/11/18 14:36:01 by rsetoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT :=			libft

BIN_DIR :=			bin
SRC_DIR :=			src
OBJ_DIR :=			build
INC_DIR :=			inc
ALL_DIR :=			${BIN_DIR} \
					${SRC_DIR} \
					${OBJ_DIR} \
					${INC_DIR}

NAME =				${BIN_DIR}/${LIBFT}.a

SRC_FILES =			ft_atoi.c \
					ft_calloc.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_memcpy.c \
					ft_memcmp.c \
					ft_memmove.c \
					ft_strchr.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strnstr.c \
					ft_tolower.c \
					ft_bzero.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_memchr.c \
					ft_memset.c \
					ft_strdup.c \
					ft_strlcpy.c \
					ft_strncmp.c \
					ft_strrchr.c \
					ft_toupper.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_isspace.c \
					ft_strcpy.c \
					ft_str_tolower.c \
					ft_str_toupper.c \
					ft_nbr_len.c \
					ft_nbr_ulen.c \
					ft_ll_itoa.c \
					ft_ll_utoa.c \
					ft_itoh.c \
					ft_chr_index.c

SRC :=				${addprefix ${SRC_DIR}/,${SRC_FILES}}
OBJ :=				${addprefix ${OBJ_DIR}/,${SRC_FILES:.c=.o}}
LIBFT_H =			${INC_DIR}/${LIBFT}.h

CC =				@clang
CFLAGS =			-Wall -Wextra -Werror
AR =				@ar -rc
RANLIB =			@ranlib
RM =				@rm -f
MSG =				@echo

# < RECIPES
${NAME}: ${ALL_DIR} ${OBJ}
	${MSG_COMPILING}
	${AR} ${NAME} ${OBJ}
	${DONE}
	${MSG_INDEX_LIB}
	${RANLIB} ${NAME}
	${DONE}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${LIBFT_H}
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

all: msg_building ${NAME}

${ALL_DIR}:
	@mkdir -p ${ALL_DIR}

clean: clean_build

fclean: clean_build clean_program

re: msg_rebuilding fclean all

.PHONY: all clean fclean re

# : CLEANING
clean_build: msg_cleaning
	${RM} ${OBJ}
	${DONE}

clean_program: msg_fcleaning
	${RM} ${NAME}
	${DONE}

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

MSG_INDEX_LIB =		${MSG} ${FG_GREY} "Indexing ${LIBFT} library..." \
					${RESET} ${NO_NL}
MSG_BUILD_LIB =		${MSG} ${FG_YELLOW} "Building ${LIBFT} library..." \
					${RESET} ${NO_NL}
MSG_COMPILING =		${MSG} ${FG_YELLOW} "Compiling ${LIBFT}..." \
					${RESET} ${NO_NL}
MSG_BUILDING =		${MSG} ${FG_ORANGE} "Building ${LIBFT} files..." \
					${RESET}
MSG_REBUILDING =	${MSG} ${FG_PINK} "Rebuilding executable..." \
					${RESET}
MSG_CLEANING =		${MSG} ${FG_BLUE} "Cleaning ${LIBFT} Build..." \
					${RESET} ${NO_NL}
MSG_FCLEANING =		${MSG} ${FG_BLUE} "Cleaning ${LIBFT} Program..." \
					${RESET} ${NO_NL}

msg_compiling:
	${MSG_COMPILING}
msg_building:
	${MSG_BUILDING}
msg_rebuilding:
	${MSG_REBUILDING}
msg_cleaning:
	${MSG_CLEANING}
msg_fcleaning:
	${MSG_FCLEANING}
msg_create_dir:
	${MSG_CREATE_DIR}
done:
	${DONE}
