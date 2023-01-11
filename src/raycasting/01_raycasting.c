/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/11 14:00:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

void	verticaldraw(t_data *data, int x)
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
		img_pixel_put(data->img, x, i, data);
		i++;
	}
}

void	getcolumns(t_data *data, int x)
{
	data->lineheight = W_HEIGHT / data->walldist;
	data->drawstart = -data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawend >= W_HEIGHT)
		data->drawend = W_HEIGHT - 1;
	verticaldraw(data, x);
}
