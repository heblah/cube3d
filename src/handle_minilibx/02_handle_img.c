/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_handle_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:25:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/11 10:07:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	clear_window(t_data *data __attribute__((unused)))
{
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	clear_window(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	return (0);
}

int	img_pixel_put(t_img *img, int x2d, int y2d, t_data *data)
{
	char	*pixel;

	if (x2d >= 0 && x2d < W_WIDTH && y2d >= 0 && y2d < W_HEIGHT)
	{
		pixel = img->addr + (y2d * img->line_len + x2d * (img->bpp / 8));
		*(int *)pixel = (int)data->color.rgb;
	}
	return (0);
}

/*
t_img	*new_img(t_data *data)
{
	t_img	*new;

	new = malloc(1 * sizeof(t_img));
	if (new == NULL)
		return (NULL);
	new->mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	new->addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line, &data->img.endian);
	data->old_img = data->img;
	data->img = new;
	//mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	// c'est plus rapide de détruire l'ancienne image que de la repeindre en noir
	return (new);
}
*/
