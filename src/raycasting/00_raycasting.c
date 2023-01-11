/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:34 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/11 10:02:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

void	init_positions(t_data *data)
{
	data->player.pos.z = 0;
	data->player.dir.x = -0.66;
	data->player.dir.y = 0;
	data->player.dir.z = 0;
	data->plane.x = 0;
	data->plane.y = 0.66;
	data->plane.z = 0;
	data->hit = 0;
}

static void	initrays(t_data *data, int x)
{
	data->cam.x = 2 * x / (double)W_WIDTH - 1;
	data->ray.x = data->player.dir.x + data->plane.x * data->cam.x;
	data->ray.y = data->player.dir.y + data->plane.y * data->cam.x;
	data->map_pos.x = (int)data->player.pos.x;
	data->map_pos.y = (int)data->player.pos.y;
}

static void	getdeltadist(t_data *data)
{
	if (data->ray.x == 0)
		data->deltadist.x = INT_MAX;
	else
		data->deltadist.x = fabs(1 / data->ray.x);
	if (data->ray.y == 0)
		data->deltadist.y = INT_MAX;
	else
		data->deltadist.y = fabs(1 / data->ray.y);
}

static void	getstep(t_data *data)
{
	if (data->ray.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x
			= (data->player.pos.x - data->map_pos.x) * data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x
			= (data->map_pos.x + 1.0 - data->player.pos.x) * data->deltadist.x;
	}
	if (data->ray.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y
			= (data->player.pos.y - data->map_pos.y) * data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedist.y
			= (data->map_pos.y + 1.0 - data->player.pos.y) * data->deltadist.y;
	}
}

static void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->map_pos.x += data->step.x;
			data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->map_pos.y += data->step.y;
			data->side = 1;
		}
		if (data->map->pxl[data->map_pos.y][data->map_pos.x] == '1')
		{
			data->hit = 1;
		}
		/*
			draw_filled_square(data->img, data->map_pos.x * 32, data->map_pos.y * 32, 32, 0x000000);
		}
		else
			draw_filled_square(data->img, data->map_pos.x * 32, data->map_pos.y * 32, 32, 0xFFFF00);
		printf("(debug-hit) char = %c (pos x: %d pos y: %d)\n",
				data->map->pxl[data->map_pos.y][data->map_pos.x],
				data->map_pos.x, data->map_pos.y);
		*/
	}
}

int	raycast(t_data *data)
{
	int	x;

	x = 0;
	init_positions(data);
	while (x < W_WIDTH)
	{
		initrays(data, x);
		getdeltadist(data);
		getstep(data);
		dda(data);
		if (data->side == 0)
			data->walldist = data->sidedist.x - data->deltadist.x;
		else
			data->walldist = data->sidedist.y - data->deltadist.y;
		getcolumns(data, x);
		x++;
	}
	return (0);
}
