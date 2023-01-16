/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/16 16:19:59 by awallet          ###   ########.fr       */
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
	data->texture.height = 128;
	data->texture.width = 128;
	if (data->side == 0)
		data->texture.wallx = data->player.pos.y + data->walldist + data->ray.y;
	else
		data->texture.wallx = data->player.pos.x + data->walldist + data->ray.x;
	data->texture.wallx -= floor(data->texture.wallx);
	data->texture.tex.x = data->texture.wallx * (double)data->texture.width;
	if (data->side == 0 && data->ray.x > 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x -1;
	if (data->side == 1 && data->ray.y < 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x -1;
	data->texture.step = 1.0 * data->texture.height / data->lineheight;
	data->texture.pos = (data->drawstart - W_HEIGHT / 2 + data->lineheight / 2)
		* data->texture.step;
}

static t_color	loadtexturecolor(t_img img, int x, int y)
{
	t_color	color;

	color.rgb = 0;
	//if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	//{
		color.rgb = *(int *)(img.addr + (y * img.line_len + x * (img.bpp / 8)));
	//}
	return (color);
}

static void	puttextures(t_data *data, int x, int y)
{
	t_color	color;

	color.rgb = 0;
	if (data->side == 1 && data->ray.x > 0) //north
	{
		color = loadtexturecolor(data->north, data->texture.tex.x, data->texture.tex.y);
		img_pixel_put(data->img, x, y, color);
	}
	else if (data->side == 1 && data->ray.x < 0) //south
	{
		color = loadtexturecolor(data->south, data->texture.tex.x, data->texture.tex.y);
		img_pixel_put(data->img, x, y, color);
	}
	else if (data->side == 0 && data->ray.x < 0) //east
	{
		color = loadtexturecolor(data->east, data->texture.tex.x, data->texture.tex.y);
		img_pixel_put(data->img, x, y, color);
	}
	else if (data->side == 0 && data->ray.x > 0) //west
	{
		color = loadtexturecolor(data->west, data->texture.tex.x, data->texture.tex.y);
		img_pixel_put(data->img, x, y, color);
	}
}

void	getscene(t_data *data, int x)
{
	getceil_floor(data, x);
	getwallsdim(data);
	getdatatexture(data);
	while (data->drawstart < data->drawend)
	{
		data->texture.tex.y = (int)data->texture.pos
			& (data->texture.height - 1);
		data->texture.pos += data->texture.step;
		puttextures(data, x, data->drawstart);
		data->drawstart++;
	}
}
