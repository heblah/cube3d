/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/30 16:07:44 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

static void	getwallsdim(t_data *data, int *line_height, int *start, int *end)
{
	*line_height = W_HEIGHT / data->walldist;
	*start = -*line_height / 2 + W_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + W_HEIGHT / 2;
	if (*end >= W_HEIGHT)
		*end = W_HEIGHT - 1;
}


static void	getdatatexture(t_data *data, int start, int line_height)
{
	data->texture.height = 128;
	data->texture.width = 128;
	if (data->side == 0)
		data->texture.wallx = data->player.pos.y + data->walldist + data->ray.y;
	else
		data->texture.wallx = data->player.pos.x + data->walldist + data->ray.x;
	data->texture.wallx -= floor(data->texture.wallx);
	data->texture.tex.x = data->texture.wallx * data->texture.width;
	if (data->side == 0 && data->ray.x > 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x - 1;
	if (data->side == 1 && data->ray.y < 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x - 1;
	data->texture.step = 1.0 * data->texture.height / line_height;
	data->texture.pos = (start - W_HEIGHT / 2
			+ line_height / 2) * data->texture.step;
}

static t_color	loadtexturecolor(t_img img, int x, int y)
{
	t_color	color;

	color.rgb = 0;
	if (x >= 0 && x < img.width && y >= 0 && y < img.height)
	{
		color.rgb = *(int *)(img.addr + (y * img.line_len + x * (img.bpp / 8)));
	}
	return (color);
}

static void	puttextures(t_data *data, int x, t_img texture)
{
	t_color	color;

	color = loadtexturecolor(texture, data->texture.tex.x, data->texture.tex.y);
	img_pixel_put(data->img, x, data->start, color);
}

void	getscene(t_data *data, int x)
{
	int	line_height;

	getwallsdim(data, &line_height, &data->start, &data->end);
	getdatatexture(data, data->start, line_height);
	while (data->start < data->end)
	{
		data->texture.tex.y = (int)data->texture.pos
			& (data->texture.height - 1);
		data->texture.pos += data->texture.step;
		if (data->side == 1 && data->ray.y < 0)
			puttextures(data, x, data->south);
		else if (data->side == 1 && data->ray.y > 0)
			puttextures(data, x, data->north);
		else if (data->side == 0 && data->ray.x < 0)
			puttextures(data, x, data->west);
		else if (data->side == 0 && data->ray.x > 0)
			puttextures(data, x, data->east);
		data->start++;
	}
}
