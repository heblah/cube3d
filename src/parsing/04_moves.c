/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:07:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 08:40:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	mvforward(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = (double)player->pos.x + player->dir.x * player->mvspeed;
	j = player->pos.y;
	if (data->map->pxl[j][i] == '0'
		|| data->map->pxl[j][i] == 'N'
		|| data->map->pxl[j][i] == 'S'
		|| data->map->pxl[j][i] == 'E'
		|| data->map->pxl[j][i] == 'W')
		player->pos.x += player->dir.x * player->mvspeed;
	i = player->pos.x;
	j = player->pos.y + player->dir.y * player->mvspeed;
	if (data->map->pxl[j][i] == '0'
		|| data->map->pxl[j][i] == 'N'
		|| data->map->pxl[j][i] == 'S'
		|| data->map->pxl[j][i] == 'E'
		|| data->map->pxl[j][i] == 'W')
		player->pos.y += player->dir.y * player->mvspeed;
}

void	mvbackward(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = player->pos.x - player->dir.x * player->mvspeed;
	j = player->pos.y;
	if (data->map->pxl[j][i] == '0'
		|| data->map->pxl[j][i] == 'N'
		|| data->map->pxl[j][i] == 'S'
		|| data->map->pxl[j][i] == 'E'
		|| data->map->pxl[j][i] == 'W')
		player->pos.x -= player->dir.x * player->mvspeed;
	i = player->pos.x;
	j = player->pos.y - player->dir.y * player->mvspeed;
	if (data->map->pxl[j][i] == '0'
		|| data->map->pxl[j][i] == 'N'
		|| data->map->pxl[j][i] == 'S'
		|| data->map->pxl[j][i] == 'E'
		|| data->map->pxl[j][i] == 'W')
		player->pos.y -= player->dir.y * player->mvspeed;
}

void	rot2right(t_data *data __attribute((unused)), t_player *player, t_dvect *plane)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dir.x;
	old_planex = plane->x;
	player->dir.x = player->dir.x * cos(player->rotspeed) - player->dir.y * sin(player->rotspeed);
	player->dir.y = old_dirx * sin(player->rotspeed) + player->dir.y * cos(player->rotspeed);

	plane->x = plane->x * cos(player->rotspeed) - plane->y * sin(player->rotspeed);
	plane->y = old_planex * sin(player->rotspeed) + plane->y * cos(player->rotspeed);
}

void	rot2left(t_data *data __attribute((unused)), t_player *player, t_dvect *plane)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dir.x;
	old_planex = plane->x;
	player->dir.x = player->dir.x * cos(-player->rotspeed) - player->dir.y * sin(-player->rotspeed);
	player->dir.y = old_dirx * sin(-player->rotspeed) + player->dir.y * cos(-player->rotspeed);

	plane->x = plane->x * cos(-player->rotspeed) - plane->y * sin(-player->rotspeed);
	plane->y = old_planex * sin(-player->rotspeed) + plane->y * cos(-player->rotspeed);
}
