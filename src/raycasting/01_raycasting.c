/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/12 16:17:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

/* used for coloring walls */
/*
static void	draw_walls(t_data *data, int x)
{
	int		i;
	t_color	color;
	t_color	s_color;

	i = data->drawstart;
	color.red = 243;
	color.green = 176;
	color.blue = 53;
	s_color.red = 48;
	s_color.green = 78;
	s_color.blue = 100;
	while (i < data->drawend)
	{
		if (data->side == 1)
			data->color = color;
		else
			data->color = s_color;
		img_pixel_put(data->img, x, i, data->color);
		i++;
	}
}
*/

static void	getwallsdim(t_data *data)
{
	data->lineheight = W_HEIGHT / data->walldist;
	data->drawstart = -data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawend >= W_HEIGHT)
		data->drawend = W_HEIGHT - 1;
}

static void	getdatatexture(t_data *data)
{
	data->texture.height = 64;
	data->texture.width = 64;
	if (data->side == 0)
		data->texture.wallx = data->player.pos.x + data->walldist + data->ray.y;
	else
		data->texture.wallx = data->player.pos.x + data->walldist + data->ray.x;
	data->texture.wallx -= floor(data->texture.wallx);
	data->texture.tex.x = data->texture.wallx * data->texture.width;
	if ((data->side == 0 && data->ray.x > 0)
		|| (data->side == 1 && data->ray.x < 0))
		data->texture.tex.x = data->texture.width - data->texture.tex.x -1;
	data->texture.step = 1.0 * data->texture.height / data->lineheight; 
	data->texture.pos = (data->drawstart- W_HEIGHT / 2 + data->lineheight / 2)
		* data->texture.step;
}

static t_color	loadtexturecolor(t_img img, int x, int y)
{
	t_color	color;

	color.rgb = *(int *)(img.addr + (y * img.line_len + x * (img.bpp / 8)));
	return (color);
}

static void	loadtextures(t_data *data, int x, int y)
{
	t_color	color;
	
	color.rgb = 0;
	if (data->side == 1 && data->ray.x > 0) //north
		img_pixel_put(&data->north, x, y, loadtexturecolor(data->north, x, y));
	else if (data->side == 1 && data->ray.x < 0) //south
		img_pixel_put(&data->south, x, y, loadtexturecolor(data->south, x, y));
	else if (data->side == 0 && data->ray.x < 0) //east
		img_pixel_put(&data->east, x, y, loadtexturecolor(data->east, x, y));
	else if (data->side == 0 && data->ray.x > 0) //west
		img_pixel_put(&data->west, x, y, loadtexturecolor(data->west, x, y));
}
/*
	if (map->wall_side == 1 && map->ray_dir_y < 0)
		draw(map, x, SOUTH);
	else if (map->wall_side == 1 && map->ray_dir_y > 0)
		draw(map, x, NORTH);
	else if (map->wall_side == 0 && map->ray_dir_x < 0)
		draw(map, x, WEST);
	else if (map->wall_side == 0 && map->ray_dir_x > 0)
		draw(map, x, EAST);
*/

void	getwalls(t_data *data, int x)
{
	int	i;

	i = 0;
	getwallsdim(data);
	getdatatexture(data); // comment to use textured walls
	while (i < W_HEIGHT)
	{
		if (i < W_HEIGHT / 2)
			img_pixel_put(data->img, x, i, data->ceil);
		else
			img_pixel_put(data->img, x, i, data->floor);
		loadtextures(data, x, i);
		i++;
	}
}
