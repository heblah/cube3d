/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/08 15:21:26 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

t_data	*getdata(void)
{
	static t_data	data;

	return (&data);
}

t_data	*initdata(void)
{
	t_data	*data;

	data = getdata();
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->old_img = NULL;
	data->garbage = NULL;
	data->map_tmp = NULL;
	data->map = NULL;
	data->north.path = NULL;
	data->south.path = NULL;
	data->east.path = NULL;
	data->west.path = NULL;
	data->ffx = 1;
	data->ffy = 1;
	data->on_zoom = false;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = initdata();
	if (argc == 2 && parser(data, argv[1]) != -1)
	{
		if (open_window(data) == MLX_ERROR || new_img(data) == NULL)
			return (MLX_ERROR);
		initplayer(data);
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask,
			&handle_keypress, data);
		mlx_hook(data->win_ptr, 6, 1L << 6, &mouse_camera, data);
		mlx_hook(data->win_ptr, 4, 1L << 2, &handle_press, NULL);
		mlx_hook(data->win_ptr, 5, 1L << 3, &handle_unpress, NULL);
		mlx_hook(data->win_ptr, 17, 1L << 0, &close_window, data);
		mlx_loop(data->mlx_ptr);
	}
	else if (argc != 2)
		ft_putstr_fd("Error: select one map.\n", 1);
	return (close_window(data), 0);
}
/*
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
		&handle_nothing, data); // handle_mouse
*/
