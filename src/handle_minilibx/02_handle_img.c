/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_handle_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:25:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 08:44:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

/*
int	clear_window(t_data *data)
{
	return (0);
}
*/

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	return (0);
}

int	img_pixel_put(t_img *img, int x, int y, t_color color)
{
	char	*pixel;

	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = (int)color.rgb;
	}
	return (0);
}

t_img	*new_img(t_data *data)
{
	data->img = memg(MALLOC, 1 * sizeof(t_img), NULL, OTHER);
	if (data->img == NULL)
		return (NULL);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	return (data->img);
}
