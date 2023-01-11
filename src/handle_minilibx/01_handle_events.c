/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:52 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/11 14:02:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	printf("keysym = %c\n", keysym);
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
