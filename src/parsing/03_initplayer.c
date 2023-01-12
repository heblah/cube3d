/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_initplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 09:15:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

static void	get_playerdata(t_player *player, int i, int j, int dir)
{
	player->pos.x = j;
	player->pos.y = i;
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
	if (dir == 'N')
	{
		data->plane.x = 0.66;
		data->plane.y = 0;
	}
	else if (dir == 'S')
	{
		data->plane.x = -0.66;
		data->plane.y = 0;
	}
	else if (dir == 'E')
	{
		data->plane.x = 0;
		data->plane.y = -0.66;
	}
	else if (dir == 'W')
	{
		data->plane.x = 0;
		data->plane.y = 0.66;
	}
}

void	initplayer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->hit = 0;
	data->player.mvspeed = 0.666;
	data->player.rotspeed = 0.1;
	while (i < data->map->row)
	{
		j = 0;
		while (j < data->map->col)
		{
			if (data->map->pxl[i][j] == 'N'
				|| data->map->pxl[i][j] == 'S'
				|| data->map->pxl[i][j] == 'E'
				|| data->map->pxl[i][j] == 'W')
			{
				get_playerdata(&data->player, i, j, data->map->pxl[i][j]);
				get_fov(data, data->map->pxl[i][j]);
			}
			j++;
		}
		i++;
	}
}
