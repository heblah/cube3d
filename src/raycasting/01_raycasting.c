/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/10 20:54:28 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

// void	verticaldraw(t_data *data, int x)
// {
// 	t_color	color;
// 	t_color	s_color;

// 	color.red = 243;
// 	color.green = 176;
// 	color.blue = 53;
// 	s_color.red = 48;
// 	s_color.green = 78;
// 	s_color.blue = 100;
// 	/* tracer les lignes correspondantes */
// }

void	getcolumns(t_data *data, int x __attribute__((unused)))
{
	data->lineheight = W_HEIGHT / data->walldist;
	data->drawstart = - data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawend >= W_HEIGHT)
		data->drawend = W_HEIGHT - 1;

	/* appeler vertical draw pour parcourir toute la hauteur */
}
