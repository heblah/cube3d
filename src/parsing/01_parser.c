/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:23:10 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/04 17:28:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

char	*rm_nl(char *gnl)
{
	int	len;

	len = ft_strlen(gnl);
	if (len > 0)
		*(gnl + len - 1) = '\0';
	return (gnl);
}
