/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:07:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 10:53:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	move(t_data *data, t_player *player, int dir)
{
	int	i;
	int	j;

	j = player->pos.x + dir * player->dir.x * player->mvspeed;
	i = player->pos.y;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
		player->pos.x += dir * player->dir.x * player->mvspeed;
	j = player->pos.x;
	i = player->pos.y + dir * player->dir.y * player->mvspeed;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
		player->pos.y += dir * player->dir.y * player->mvspeed;
}

void	rotation(t_player *player, t_dvect *plane, int dir)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dir.x;
	old_planex = plane->x;
	player->dir.x = player->dir.x * cos(dir * player->rotspeed)
		- player->dir.y * sin(dir * player->rotspeed);
	player->dir.y = old_dirx * sin(dir * player->rotspeed)
		+ player->dir.y * cos(dir * player->rotspeed);
	plane->x = plane->x * cos(dir * player->rotspeed)
		- plane->y * sin(dir * player->rotspeed);
	plane->y = old_planex * sin(dir * player->rotspeed)
		+ plane->y * cos(dir * player->rotspeed);
}

/*
void	mvforward(t_data *data, t_player *player)
{
	int	i;
	int	j;

	j = player->pos.x + player->dir.x * player->mvspeed;
	i = player->pos.y;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
		player->pos.x += player->dir.x * player->mvspeed;
	j = player->pos.x;
	i = player->pos.y + player->dir.y * player->mvspeed;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
		player->pos.y += player->dir.y * player->mvspeed;
}

void	mvbackward(t_data *data, t_player *player)
{
	int	i;
	int	j;

	j = player->pos.x - player->dir.x * player->mvspeed;
	i = player->pos.y;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
		player->pos.x -= player->dir.x * player->mvspeed;
	j = player->pos.x;
	i = player->pos.y - player->dir.y * player->mvspeed;
	if (data->map->pxl[i][j] == '0'
		|| data->map->pxl[i][j] == 'N'
		|| data->map->pxl[i][j] == 'S'
		|| data->map->pxl[i][j] == 'E'
		|| data->map->pxl[i][j] == 'W')
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
*/
