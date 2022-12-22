/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/22 14:29:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

/*
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
		data = NULL;
	return (0);
}

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
