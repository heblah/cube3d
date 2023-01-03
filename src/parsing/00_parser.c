/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/03 16:49:24 by halvarez         ###   ########.fr       */
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

static int	get_texture(char *path)
{
	if (check_extension(".xpm", path) == false)
		return (-1);
	return (openfile(path));
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
			data->fd_no = get_texture(gnl + 3);
		else if (ft_strncmp(gnl, "SO ", 3) == 0)
			data->fd_so = get_texture(gnl + 3);
		else if (ft_strncmp(gnl, "WE ", 3) == 0)
			data->fd_we = get_texture(gnl + 3);
		else if (ft_strncmp(gnl, "EA ", 3) == 0)
			data->fd_ea = get_texture(gnl + 3);
		else if (ft_strncmp(gnl, "F ", 2) == 0)
		else if (ft_strncmp(gnl, "C ", 2) == 0)
		else if (ft_isdigit(*gnl) == true)

	}
	return (fd);
}
