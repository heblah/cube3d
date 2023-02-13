/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:45:58 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 13:01:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	mouse_camera(int x, int y, t_data *data)
{
	(void)y;
	if (x < W_WIDTH / 3.5)
		rotation(&data->player, &data->plane, -1);
	else if (x > W_WIDTH / 1.3)
		rotation(&data->player, &data->plane, 1);
	return (0);
}

int	handle_press(int mouse_id)
{
	t_data	*data;

	data = getdata();
	if (mouse_id == 1)
	{
		data->ffx += 1.5;
		data->ffy -= 0.08;
	}
	return (0);
}

int	handle_unpress(int mouse_id)
{
	t_data	*data;

	data = getdata();
	if (mouse_id == 1)
	{
		data->ffx -= 1.5;
		data->ffy += 0.08;
	}
	return (0);
}
