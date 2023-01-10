/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:04:17 by awallet           #+#    #+#             */
/*   Updated: 2023/01/10 22:03:40 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

//quelques tests je continue plus tard :p
//img_put_pix a faire pour gagner en opti.
void	draw_filled_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + size)
	{
		j = y - 1;
		while (++j < y + size)
			img_pix_put(img, i, j, color);
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_background(data->img, 0x0000FF);
	while (++y < data->map->row)
	{
		x = -1;
		while (++x < data->map->col)
		{
			if (data->map->pxl[y][x] == '1' || data->map->pxl[y][x] == ' ')
				draw_filled_square(data->img, x * 32, y * 32, 32, 0x00FF00);
			else if (data->map->pxl[y][x] == 'N' || data->map->pxl[y][x] == 'S'
				|| data->map->pxl[y][x] == 'W' || data->map->pxl[y][x] == 'E')
			{
				if (data->player.pos.x == 0 && data->player.pos.y == 0)
				{
					data->player.pos.x = (double)x;
					data->player.pos.y = (double)y;
				}
				printf("(debug-ray) (pos y: %f pos x: %f)\n",
					data->player.pos.y, data->player.pos.x);
				draw_filled_square(data->img, data->player.pos.x * 32, data->player.pos.y * 32, 32, 0xFF0000);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
}
