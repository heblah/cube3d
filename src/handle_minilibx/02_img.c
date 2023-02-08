/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:03:56 by awallet           #+#    #+#             */
/*   Updated: 2023/02/08 15:45:10 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	init_minimap(t_data *data)
{
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr,
			data->map->row * 8, data->map->col * 8);
	if (!data->minimap.mlx_img)
		return ;
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	if (!data->minimap.addr)
		return ;
}
