/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/22 16:18:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

t_data	*getdata(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv __attribute__((unused)))
{
	t_data	*data;

	data = getdata();
	if (argc == 2)
	{
		if (init_data(data) == MLX_ERROR || open_window(data) == MLX_ERROR)
			return (MLX_ERROR);
		/*
		new_img(&data);
		mlx_loop_hook(data.mlx_ptr, &render, &data);
		*/
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask,
			&handle_keypress, &data);
		mlx_hook(data->win_ptr, 17, 1L << 0, &close_window, data);
		mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
			&handle_nothing, data); /* handle_mouse */
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_putstr_fd("Select one map.\n", 1);
	return (close_window(data), 0);
}
