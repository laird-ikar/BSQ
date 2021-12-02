/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_map_to_machinable_things.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:56:51 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:57:27 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RE_MAP_TO_MACHINABLE_THINGS_H
# define RE_MAP_TO_MACHINABLE_THINGS_H

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

void	re_map_to_machinable_things(int fd, char *rules,
			t_point board_size, int **tab);

#endif
