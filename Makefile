# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awallet <awallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2023/01/11 13:29:58 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
build		:= san

#Compilation of the mandatory part
NAME    	= cube3D

MAIN_DIR	= ./src/main/
MAIN		= 00_main.c
MAIN		+= 
SRC			+= $(addprefix ${MAIN_DIR}, ${MAIN})

PARS_DIR	= ./src/parsing/
PARS		= 00_parser.c 01_parser.c 02_parser.c 03_initplayer.c
PARS		+= 
SRC			+= $(addprefix ${PARS_DIR}, ${PARS})

LIBX_DIR	= ./src/handle_minilibx/
LIBX		= 00_handle_window.c 01_handle_events.c 02_handle_img.c
LIBX		+= 
SRC			+= $(addprefix ${LIBX_DIR}, ${LIBX})

MTRX_DIR	= ./src/matrix/
MTRX		= 00_matrix_utils.c
MTRX		+= 
SRC			+= $(addprefix ${MTRX_DIR}, ${MTRX})

RAY_DIR 	= ./src/raycasting/
RAY			= 00_raycasting.c 01_raycasting.c ray.c
RAY			+=
SRC			+= $(addprefix ${RAY_DIR}, ${RAY})

UTILS_DIR	= ./src/utils/
UTILS		= 00_garbage_memory.c 01_list.c
UTILS		+= 
SRC			+= $(addprefix ${UTILS_DIR}, ${UTILS})

OBJ			= ${SRC:.c=.o}
DEP			= ${OBJ:.o=.d}

#Libraries
OMLX		= -I/usr/include -Imlx_linux
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lXext -lX11
CLIB		+= -lz -Llibft -lft

#Conditionnal flags depending on the building version
cflags.rls		:= -Wall -Wextra -Werror -MMD -MP -Isrc -Ilibft -Imlx_linux
cflags.gdb		:= -g3
cflags.san		:= -g3 -fsanitize=address
CFLAGS			= ${cflags.rls} ${cflags.${build}}
export			CFLAGS

#Rules to other makefiles
CC			= cc
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

%.o : %.c	
		${CC} ${CFLAGS} -c $< -o $@

#Rules to compile
${NAME}:${OBJ}
		${MAKE} -C mlx_linux 
		${MAKE} -eC libft
		${CC} ${CFLAGS} ${OBJ} ${OMLX} ${CLIB} -o ${NAME}

all:    ${NAME}

bonus:	all

hgen:
	cd src; ./hgenerator ft_cube3d.h
	cd -

#Cleaning rules
clean:
		${RM} ${OBJ} ${DEP}
		${MAKE} clean -C mlx_linux
		${MAKE} clean -C libft

fclean: clean
		${RM} ${NAME}
		${MAKE} clean -C libft

re:     fclean all

#Dependencies list
-include ${DEP}

.PHONY: all clean fclean re bonus hgen
