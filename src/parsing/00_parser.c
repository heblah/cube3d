/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/04 18:16:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

static t_bool	check_extension(char *ext, char *file)
{
	int	len_ext;
	int	len_file;

	len_ext = ft_strlen(ext);
	len_file = ft_strlen(file);
	if (ft_strncmp(ext, file + len_file - len_ext, len_ext) != 0)
		return (false);
	return (true);
}

static int	openfile(char *path2file, char *ext)
{
	int	fd;

	if (ext != NULL && check_extension(ext, path2file) == false)
		return (-1);
	fd = open(path2file, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(path2file, O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	else
	{
		if (close(fd) == -1)
			return (ft_putstr_fd("Error closing the file", 2),
				ft_putstr_fd(path2file, 2),
				ft_putstr_fd(".\n", 2), -1);
		else
			return (-1);
	}
	return (fd);
}

static char	*get_texture(char *path)
{
	char	*texture;
	int		fd;

	texture = NULL;
	fd = openfile(path, ".xpm");
	if (check_extension(".xpm", path) == true && fd != -1)
	{
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error closing the file", 2);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(".\n", 2);
		}
		texture = ft_strdup(path);
		return (memg(MALLOC, 0, texture, PARSE), texture);
	}
	else if (check_extension(".xpm", path) == false)
		ft_putstr_fd("Error : texture has to be in xpm format.\n", 2);
	return (NULL);
}

static t_color	getcolor(char *color_txt)
{
	t_color	color;
	int		i;

	color.rgb = 0;
	i = 0;
	while (*(color_txt + i))
	{
		if ((color_txt[i] < '0' || color_txt[i] > '9') && color_txt[i] != ',')
			return (ft_putstr_fd("Error : wrong format color.\n", 2), color);
		i++;
	}
	color.red = ft_atoi(color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	color.green = ft_atoi(++color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	color.blue = ft_atoi(++color_txt);
	return (color);
}

int	parser(t_data *data, char *path2map)
{
	int		fd;
	char	*gnl;

	fd = openfile(path2map, ".cub");
	if (fd == -1)
		return (ft_putstr_fd("Error : invalid map.\n", 2), -1);
	gnl = rm_nl(get_next_line(fd));
	while (gnl != NULL)
	{
		memg(MALLOC, 0, gnl, PARSE);
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
		else if (*gnl == '1' || *gnl == ' ' || *gnl == '\t')
			list_addback(&data->map_tmp, gnl);
		gnl = rm_nl(get_next_line(fd));
		printf("size list = %ld\n", listlen(data->map_tmp));
	}
	return (fd);
}
