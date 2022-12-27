# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/12/27 11:07:43 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
build		:= san

#Compilation of the mandatory part
NAME    	= cube3D
SRCS_DIR	= ./src/
SRCS		= 00_main.c 01_window_management.c 02_handle_events.c #03_handle_img.c
SRCS		+= 
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

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
${NAME}:${OBJS}
		${MAKE} -C mlx_linux 
		${MAKE} -eC libft
		${CC} ${CFLAGS} ${OBJS} ${OMLX} ${CLIB} -o ${NAME}

all:    ${NAME}

bonus:	all

hgen:
	cd src; ./hgenerator ft_cube3d.h
	cd -

#Cleaning rules
clean:
		${RM} ${OBJS} ${DEPS}
		${MAKE} clean -C mlx_linux
		${MAKE} clean -C libft

fclean: clean
		${RM} ${NAME}
		${MAKE} clean -C libft

re:     fclean all

#Dependencies list
-include ${DEPS}

.PHONY: all clean fclean re bonus hgen
