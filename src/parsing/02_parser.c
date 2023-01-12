/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:48:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 15:47:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

static t_bool	isempty(t_matrix *map, int i, int j)
{
	if (i - 1 > 0
		&& (map->pxl[i - 1][j] == ' ' || map->pxl[i - 1][j] == '\t'))
		return (true);
	else if (j - 1 > 0
		&& (map->pxl[i][j - 1] == ' ' || map->pxl[i][j - 1] == '\t'))
		return (true);
	else if (i + 1 < map->row
		&& (map->pxl[i + 1][j] == ' ' || map->pxl[i + 1][j] == '\t'))
		return (true);
	else if (j + 1 < map->col
		&& (map->pxl[i][j + 1] == ' ' || map->pxl[i][j + 1] == '\t'))
		return (true);
	else if ((j + 1 == map->col && map->pxl[i][j] == '0')
		|| (i + 1 == map->row && map->pxl[i][j] == '0'))
		return (true);
	return (false);
}

static t_bool	wall_around(t_matrix *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if ((map->pxl[i][j] == '0'
				|| map->pxl[i][j] == 'N'
				|| map->pxl[i][j] == 'E'
				|| map->pxl[i][j] == 'W'
				|| map->pxl[i][j] == 'S')
				&& isempty(map, i, j) == true)
			{
				ft_putstr_fd("Error: the map is not surrounded by walls.\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static unsigned int	player(t_matrix *map)
{
	unsigned int	n;
	int				i;
	int				j;

	n = 0;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->pxl[i][j] == 'N'
				|| map->pxl[i][j] == 'E'
				|| map->pxl[i][j] == 'W'
				|| map->pxl[i][j] == 'S')
			{
				n++;
			}
			j++;
		}
		i++;
	}
	if (n != 1)
		ft_putstr_fd("Error : number of player on the map != 1.\n", 2);
	return (n);
}

t_bool	checkparsing(t_data *data)
{
	if (data->floor.rgb == UINT_MAX
		|| data->ceil.rgb == UINT_MAX
		|| data->north.mlx_img == NULL
		|| data->south.mlx_img == NULL
		|| data->west.mlx_img == NULL
		|| data->east.mlx_img == NULL
		|| wall_around(data->map) == false
		|| player(data->map) != 1)
		return (false);
	memg(FREE, 0, NULL, PARSE);
	data->map_tmp = NULL;
	return (true);
}
