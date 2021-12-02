/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_corners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:58:10 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:47:28 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_corners.h"

void	get_corners(t_point *corners, int x, int y, int size)
{
	corners[0].x = x;
	corners[0].y = y;
	corners[1].x = x + size;
	corners[1].y = y;
	corners[2].x = x;
	corners[2].y = y + size;
	corners[3].x = x + size;
	corners[3].y = y + size;
}

int	map_x(int width, int size, int n)
{
	if (size == width)
		return (0);
	else
		return (n / (width - size));
}

int	map_y(int width, int size, int n)
{
	if (size == width)
		return (n);
	else
		return (n % (width - size));
}
