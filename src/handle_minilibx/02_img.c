/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:03:56 by awallet           #+#    #+#             */
/*   Updated: 2023/02/08 16:24:59 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	minimap_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > W_HEIGHT - 1 || x < 0
		|| x > W_WIDTH - 1)
		return ;
	pixel = (data->minimap.addr + (y * data->minimap.line_len
				+ x * (data->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	draw_filled(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + 10)
	{
		j = y - 1;
		while (++j < y + 10)
			minimap_pix_put(data, i, j, color);
	}
}

void	update_minimap(t_data *data)
{
	print_map(data);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->row)
	{
		x = -1;
		while (++x < data->map->col)
		{
			if (data->map->pxl[y][x] == '1' || data->map->pxl[y][x] == ' ')
				draw_filled(data, x * 10, y * 10, 0x00FF00);
			else if (data->map->pxl[y][x] == 'N' || data->map->pxl[y][x] == 'S'
				|| data->map->pxl[y][x] == 'W' || data->map->pxl[y][x] == 'E')
			{
				if (data->player.pos.x != 0 && data->player.pos.y != 0)
					draw_filled(data, data->player.pos.x * 10 - 0.5,
						data->player.pos.y * 10 - 0.5, 0xFF0000);
				else
					draw_filled(data, x * 10, y * 10, 0xFF0000);
			}
			else
				draw_filled(data, x * 10, y * 10, 0x000000);
		}
	}
}

void	init_minimap(t_data *data)
{
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr,
			data->map->col * 10, data->map->row * 10);
	if (!data->minimap.mlx_img)
		return ;
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	if (!data->minimap.addr)
		return ;
	print_map(data);
}
