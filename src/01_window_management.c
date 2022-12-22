/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_window_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:40:03 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/22 15:11:42 by halvarez         ###   ########.fr       */
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
	printf("data->mlx_ptr =\t%p\n", data->mlx_ptr);
	printf("data->img =\t%p\n", data->img);
	printf("data->win_ptr =\t%p\n", data->win_ptr);
	if (data->mlx_ptr && data->img && data->img->mlx_img)
	{
		DBG
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		data->img->mlx_img = NULL;
	}
	if (data->mlx_ptr && data->win_ptr)
	{
		DBG
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	printf("here: %s:%d\n", __func__, __LINE__);
	/* free all */
	return (exit(0), 0);
}

int	init_data(t_data *data)
{
	data = NULL;
	return (0);
}

