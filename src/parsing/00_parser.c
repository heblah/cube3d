/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/03 18:04:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

t_bool	check_extension(char *ext, char *file)
{
	int	len_ext;
	int	len_file;

	len_ext = ft_strlen(ext);
	len_file = ft_strlen(file);
	if (ft_strncmp(ext, file + len_file - len_ext, len_ext) != 0)
		return (false);
	return (true);
}

static int	openfile(char *path2file)
{
	int	fd;

	if (check_extension(".cub", path2file) == false)
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

	texture = NULL;
	if (check_extension(".xpm", path) == true && openfile(path) != -1)
	{
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error closing the file", 2);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(".\n", 2);
		}
		texture = ft_strdup(path);
		return (memg(MALLOC, 0, texture, PARS), texture);
	}
	else if (check_extension(".xpm", path) == false)
		ft_pustr_fd("Error : texture has to be in xpm format.\n", 2);
	return (NULL);
}

static t_color	getcolor(char *color_txt)
{
	t_color	color;
	char	r[4];
	char	g[4];
	char	b[4];
	int		i;

	while (*(color_txt + i))
	{
		//parcourir la string et injecter les rgb dans color
	}
	return (color);
}

int	parser(t_data *data __attribute__((unused)), char *path2map)
{
	int		fd;
	char	*gnl;

	fd = openmap(path2map);
	if (fd == -1)
		return (ft_putstr_fd("Error : invalid map.\n", 2), -1);
	gnl = get_next_line(fd);
	while (gnl != NULL)
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
		else if (ft_isdigit(*gnl) == true)

	}
	return (fd);
}
