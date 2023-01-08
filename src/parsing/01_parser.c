/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:10 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/08 12:35:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

char	*rm_nl(char *gnl)
{
	int	len;

	len = ft_strlen(gnl);
	if (len > 0 && *(gnl + len - 1) == '\n')
		*(gnl + len - 1) = '\0';
	return (gnl);
}

void	getmapdata(t_data *data, char *gnl)
{
	if (ft_strncmp(gnl, "NO ", 3) == 0)
		data->no_txt = get_texture(gnl + 3);
	else if (ft_strncmp(gnl, "SO ", 3) == 0)
		data->so_txt = get_texture(gnl + 3);
	else if (ft_strncmp(gnl, "WE ", 3) == 0)
		data->we_txt = get_texture(gnl + 3);
	else if (ft_strncmp(gnl, "EA ", 3) == 0)
		data->ea_txt = get_texture(gnl + 3);
	else if (ft_strncmp(gnl, "F ", 2) == 0)
		data->floor = getcolor(gnl + 2);
	else if (ft_strncmp(gnl, "C ", 2) == 0)
		data->ceil = getcolor(gnl + 2);
}

static t_bool ischarmap(char *line)
{
	size_t	i;

	i = 0;
	while (*(line + i))
	{
		if (*(line + i) != '1'
			&& *(line + i) != '0'
			&& *(line + i) != ' '
			&& *(line + i) != '\t'
			&& *(line + i) != 'N'
			&& *(line + i) != 'S'
			&& *(line + i) != 'W'
			&& *(line + i) != 'E')
			return (false);
		i++;
	}
	return (true);
}

static int	linesize(t_list *first)
{
	int	len;
	int	i;

	len = 0;
	while (first)
	{
		i = 0;
		while (*(first->data + i))
		{
			if (i >= len)
				len++;
			i++;
		}
		first = first->next;
	}
	return (len);
}

int	convertmap(t_data *data, t_list	*maptmp)
{
	int	row;
	int	col;
	int	i;
	int	j;

	row = listlen(maptmp);
	col = linesize(maptmp);
	i = 0;
	data->map = new_matrix(row, col);
	if (data->map == NULL)
		return (false);
	while (maptmp)
	{
		if (ischarmap(maptmp->data) == false)
			return (false);
		j = -1;
		while (++j < col && *(maptmp->data + j))
			data->map->pxl[i][j] = maptmp->data[j];
		while (j < col)
			data->map->pxl[i][j++] = ' ';
		printf("map[%d] = %ls\n", i, data->map->pxl[i]);
		maptmp = maptmp->next;
		i++;
	}
	return (true);
}
