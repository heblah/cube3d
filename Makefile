# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/12/21 18:33:13 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Default build version = release
build		:=

#Compilation of the mandatory part
NAME    	= fdf
SRCS_DIR	= ./src/
SRCS		= 00_main.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})

#Libraries
OMLX		= -I/usr/include -Imlx_linux
CLIB		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lXext -lX11
CLIB		+= -lz -Llibft -lft

#Conditionnal flags depending on the building version
cflags.rls		:= -Wall -Wextra -Werror -MMD -MP
cflags.gdb		:= -g3
cflags.san		:= -g3 -fsanitize=address
CFLAGS			= ${cflags.rls} ${cflags.${BUILD}}

#Rules to other makefiles
CC			= cc
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:	
		${CC} ${CFLAGS} ${OMLX} -c $< -o $@

#Rules to compile
${NAME}:${OBJS}
		${MAKE} -C mlx_linux 
		${MAKE} -C libft
		${CC} ${CFLAGS} ${OBJS} ${CLIB} -o ${NAME}

all:    hgen ${NAME}

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
