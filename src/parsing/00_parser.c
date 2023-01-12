/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 16:28:58 by halvarez         ###   ########.fr       */
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

void	get_texture(t_data *data, char *path, t_img *img)
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
		printf("path = %s\n", path);
		printf("img = %p\n", img);
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img->width, &img->height);
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	}
	else if (check_extension(".xpm", path) == false)
		ft_putstr_fd("Error : texture has to be in xpm format.\n", 2);
}

t_color	getcolor(char *color_txt)
{
	t_color	color;
	int		red;
	int		green;
	int		blue;
	int		i;

	color.rgb = UINT_MAX;
	i = -1;
	while (*(color_txt + ++i))
		if ((color_txt[i] < '0' || color_txt[i] > '9') && color_txt[i] != ',')
			return (ft_putstr_fd("Error : wrong format color.\n", 2), color);
	red = ft_atoi(color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	green = ft_atoi(++color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	blue = ft_atoi(++color_txt);
	if (red < 0 || green < 0 || blue < 0
		|| red > 255 || green > 255 || blue > 255)
		return (ft_putstr_fd("Error : wrong format color.\n", 2), color);
	color.rgb = 0;
	return (color.red = red, color.green = green, color.blue = blue, color);
}

int	parser(t_data *data, char *path2map)
{
	int		fd;
	char	*gnl;

	fd = openfile(path2map, ".cub");
	if (fd == -1)
		return (ft_putstr_fd("Error : invalid map extension.\n", 2), -1);
	gnl = rm_nl(get_next_line(fd));
	while (gnl != NULL)
	{
		memg(MALLOC, 0, gnl, PARSE);
		if (*gnl >= 'A' && *gnl <= 'Z')
			getmapdata(data, gnl);
		else if (*gnl == '1' || *gnl == ' ' || *gnl == '\t')
			list_addback(&data->map_tmp, gnl);
		gnl = rm_nl(get_next_line(fd));
	}
	if (convertmap(data, data->map_tmp) == false)
		return (ft_putstr_fd("Error : wrong map format.\n", 2), -1);
	if (checkparsing(data) == false)
		return (-1);
	return (fd);
}
