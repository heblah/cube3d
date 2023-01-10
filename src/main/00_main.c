/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/10 21:13:57 by awallet          ###   ########.fr       */
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
	data->img = NULL;
	data->garbage = NULL;
	data->map_tmp = NULL;
	data->map = NULL;
	data->no_txt = NULL;
	data->so_txt = NULL;
	data->we_txt = NULL;
	data->ea_txt = NULL;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = initdata();
	if (argc == 2 && parser(data, argv[1]) != -1)
	{
		if (open_window(data) == MLX_ERROR)
			return (MLX_ERROR);
		/*
		new_img(&data);
		mlx_loop_hook(data.mlx_ptr, &render, &data);
		*/
		data->img = memg(MALLOC, sizeof(t_img), NULL, OTHER);
		data->img->mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
		data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
				&data->img->line_len, &data->img->endian);
		data->player.pos.x = 0;
		data->player.pos.y = 0;
		print_map(data);
		raycast(data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask,
			&handle_keypress, &data);
		mlx_hook(data->win_ptr, 17, 1L << 0, &close_window, data);
		mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
			&handle_nothing, data); /* handle_mouse */
		mlx_loop(data->mlx_ptr);
	}
	else if (argc != 2)
		ft_putstr_fd("Select one map.\n", 1);
	return (close_window(data), 0);
}
