/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_matrix_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:59:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/21 18:18:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

t_matrix	*init_vector(t_matrix *pt, int x3d, int y3d, int z3d)
{
	if (pt != NULL)
	{
		pt->pxl[x][0] = x3d;
		pt->pxl[y][0] = y3d;
		pt->pxl[z][0] = z3d;
	}
	return (pt);
}

t_matrix	*new_vector(int x3d, int y3d, int z3d)
{
	t_matrix	*vector;

	vector = new_matrix(3, 1);
	if (!vector)
		return (NULL);
	vector->pxl[x][v1] = x3d;
	vector->pxl[y][v1] = y3d;
	vector->pxl[z][v1] = z3d;
	return (vector);
}
