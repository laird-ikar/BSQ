/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_square.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:11:45 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 17:55:42 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_EMPTY_SQUARE_H
# define CHECK_EMPTY_SQUARE_H

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

int	is_square_empty(int **board, t_point nw, int size);

#endif
