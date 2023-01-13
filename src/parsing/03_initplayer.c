/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_initplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/13 18:13:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

/*
	inverting axes to take into account the screen orientation
	player(x,y) = (j, i)
*/
static void	get_playerdata(t_player *player, int x, int y, int dir)
{
	player->pos.x = x;
	player->pos.y = y;
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

static void	get_fov(t_data *data, int dir)
{
	double	fov;

	fov = 0.66;
	if (dir == 'N')
	{
		data->plane.x = fov;
		data->plane.y = 0;
	}
	else if (dir == 'S')
	{
		data->plane.x = -fov;
		data->plane.y = 0;
	}
	else if (dir == 'E')
	{
		data->plane.x = 0;
		data->plane.y = -fov;
	}
	else if (dir == 'W')
	{
		data->plane.x = 0;
		data->plane.y = fov;
	}
}

void	initplayer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->hit = 0;
	data->player.mvspeed = 0.5;
	data->player.rotspeed = 0.1;
	while (x < data->map->row)
	{
		y = 0;
		while (y < data->map->col)
		{
			if (data->map->pxl[x][y] == 'N'
				|| data->map->pxl[x][y] == 'S'
				|| data->map->pxl[x][y] == 'E'
				|| data->map->pxl[x][y] == 'W')
			{
				get_playerdata(&data->player, x, y, data->map->pxl[x][y]);
				get_fov(data, data->map->pxl[x][y]);
			}
			y++;
		}
		x++;
	}
}
