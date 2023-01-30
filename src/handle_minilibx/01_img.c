/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:25:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/30 16:35:06 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			if (y < W_HEIGHT / 2)
				img_pixel_put(data->img, x, y, data->ceil);
			else
				img_pixel_put(data->img, x, y, data->floor);
			y++;
		}
		++x;
	}
}

void	debug_total(t_data *data)
{
	fprintf(data->fd, "=========== DEBUG ===============\n");
	fprintf(data->fd, "perpwalldist=%f\n", data->walldist);
	fprintf(data->fd, "player_pos(x,y)=%f,%f\n", data->player.pos.x, data->player.pos.y);
	fprintf(data->fd, "plane(x,y)=%f,%f\n", data->plane.x, data->plane.y);
	fprintf(data->fd, "step(x,y)=%i,%i\n", data->step.x, data->step.y);
	fprintf(data->fd, "map_pos(x,y)=%i,%i\n", data->map_pos.x, data->map_pos.y);
	fprintf(data->fd, "cam(x,y)=%f,%f\n", data->cam.x, data->cam.y);
	fprintf(data->fd, "tex(x,y)=%d,%d\n", data->texture.tex.x, data->texture.tex.y);
	fprintf(data->fd, "deltadist=%f,%f\n", data->deltadist.x, data->deltadist.y);
	fprintf(data->fd, "sidedist=%f,%f\n", data->sidedist.x, data->sidedist.y);
	fprintf(data->fd, "start/end=%i,%i\n", data->start, data->end);
	fprintf(data->fd, "texture_step=%f\n", data->texture.step);
	fprintf(data->fd, "texture_pos=%f\n", data->texture.pos);
	fprintf(data->fd, "texture_wallx=%f\n", data->texture.wallx);
}

int	render(t_data *data)
{
	static int	i = 0;

	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	background(data); //doesnt work ???
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->mlx_img, 0, 0);
	debug_total(data);
	i++;
	return (0);
}

void	img_pixel_put(t_img *img, int x, int y, t_color color)
{
	char	*pixel;

	if (y < 0 || y > W_HEIGHT - 1 || x < 0
		|| x > W_WIDTH - 1)
		return ;
	pixel = img->addr + (y * img->line_len
			+ x * (img->bpp / 8));
	*(int *)pixel = color.rgb;
}

static void	loadtextures(t_data *data)
{
	data->north.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->north.path, &data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.mlx_img, &data->north.bpp,
			&data->north.line_len, &data->north.endian);
	data->south.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->south.path,
			&data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.mlx_img, &data->south.bpp,
			&data->south.line_len, &data->south.endian);
	data->west.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->west.path,
			&data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.mlx_img, &data->west.bpp,
			&data->west.line_len, &data->west.endian);
	data->east.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->east.path,
			&data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.mlx_img, &data->east.bpp,
			&data->east.line_len, &data->east.endian);
}

t_img	*new_img(t_data *data)
{
	data->img = memg(MALLOC, 1 * sizeof(t_img), NULL, OTHER);
	if (data->img == NULL)
		return (NULL);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	loadtextures(data);
	return (data->img);
}
