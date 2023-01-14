/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:40:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/14 14:01:55 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT,
			"Cube 3D");
	if (data->win_ptr == NULL)
		return (free(data->mlx_ptr), MLX_ERROR);
	return (0);
}

int	close_window(t_data *data)
{
	if (data
		&& data->img != NULL
		&& data->img->mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		data->img->mlx_img = NULL;
	}
	if (data->mlx_ptr && data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	memg(PURGE, 0, NULL, 0);
	return (exit(0), 0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == 'w')
		move(data, &data->player, 1);
	else if (keysym == 'a')
		rotation(&data->player, &data->plane, 1);
	else if (keysym == 's')
		move(data, &data->player, -1);
	else if (keysym == 'd')
		rotation(&data->player, &data->plane, -1);
	return (0);
}
