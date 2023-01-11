/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:52 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/11 17:07:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == 'w')
		mvforward(data, &data->player);
	else if (keysym == 'a')
		rot2left(data, &data->player, &data->plane);
	else if (keysym == 's')
		mvbackward(data, &data->player);
	else if (keysym == 'd')
		rot2right(data, &data->player, &data->plane);
	printf("keysym = %d\n", keysym);
	return (0);
}
/*
	else if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
		data = NULL;
*/

/*
int	handle_mouse(int keysym, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keysym == 4 || keysym == 5)
		key_zoom(data, keysym);
	return (0);
}
*/

int	handle_nothing(void)
{
	return (0);
}
