/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:04:17 by awallet           #+#    #+#             */
/*   Updated: 2023/01/06 01:03:03 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

//quelques tests je continue plus tard :p
//img_put_pix a faire pour gagner en opti.
void	draw_filled_square(void *mlx, void *win, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + size)
	{
		j = y - 1;
		while (++j < y + size)
			mlx_pixel_put(mlx, win, i, j, color);
	}
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++y < data->map->row)
	{
		x = -1;
		printf("line = %d\n", y);
		while (++x < data->map->col)
		{
			printf("data = [y:%d][x:%d] / %c\n", y, x, data->map->pxl[y][x]);
			if (data->map->pxl[y][x] == '1' || data->map->pxl[y][x] == ' ')
				draw_filled_square(data->mlx_ptr, data->win_ptr, x * 64, y * 64, 64, 0x00FF00);
			else if (data->map->pxl[y][x] == 'N' || data->map->pxl[y][x] == 'S'
				|| data->map->pxl[y][x] == 'W' || data->map->pxl[y][x] == 'E')
				draw_filled_square(data->mlx_ptr, data->win_ptr, x * 64, y * 64, 64, 0xFF0000);
		}
	}
}
