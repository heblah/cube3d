/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:48:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/05 15:12:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

t_bool	checkparsing(t_data *data)
{
	if (data->floor.rgb == UINT_MAX
		|| data->ceil.rgb == UINT_MAX
		|| data->no_txt == NULL
		|| data->so_txt == NULL
		|| data->we_txt == NULL
		|| data->ea_txt == NULL)
		return (false);
	memg(FREE, 0, NULL, PARSE);
	data->map_tmp = NULL;
	return (true);
}
