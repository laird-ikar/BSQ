/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_corners.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:45:18 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:47:42 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CORNERS_H
# define GET_CORNERS_H

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

void	get_nth_square(t_point *corners, t_point tab_size, int size, int n);
void	get_corners(t_point *corners, int x, int y, int size);
int		map_x(int width, int size, int n);
int		map_y(int width, int size, int n);

#endif
