/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cube3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/03 10:40:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CUBE3D_H
# define T_CUBE3D_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include "ft_libft.h"
# include "mlx.h"

# define DBG printf("here: %s:%d\n", __func__, __LINE__);
# define W_WIDTH		1920
# define W_HEIGHT		1080
# define MLX_ERROR 		-1
# define BACKGROUND 	0x2F4F4F
# define GREEN		 	0x3A9D23
# define RED		 	0xFF0000
# define BLUE 			0x000FFF
# define YELLOW			0xFFFF00
# define ORANGE 		0xFF8C00
# define WHITE	 		0xFFFFFF
# define BLACK	 		0x000000

/* t_img ==================================================================== */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* t_matrix : matrix of space coordinates =================================== */
typedef struct s_matrix
{
	double	**pxl;
	int		i;
	int		row;
	int		j;
	int		col;
}			t_matrix;

/* Label for garbage ======================================================== */
typedef enum e_label
{
	INIT,
	PARSE,
	LIBFT,
	OTHER,
}	t_label;

typedef enum e_memt
{
	MALLOC,
	FREE,
	PURGE,
	LABEL
}	t_memt;


/* Garbage collector structure ============================================== */
typedef struct s_garbage
{
	void				*address;
	t_label				label;
	struct s_garbage	*next;
}					t_garbage;

/* t_data =================================================================== */
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*old_img;
	t_img		*img;
	t_garbage	*garbage;
}				t_data;

/* e_freeflag : to chose what matrix freed ================================== */
enum e_freeflag
{
	nofree = 1 << 0,
	free_a = 1 << 1,
	free_b = 1 << 2,
};
#endif
