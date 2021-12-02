/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_square.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:43:48 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:47:09 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BIG_SQUARE_H
# define FIND_BIG_SQUARE_H

# include <stdio.h>
# include <unistd.h>

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

void	find_biggest_square(int **board, t_point board_size, char *rules);
int		ft_min(int a, int b);
void	add_square(int **board, t_point nw, int size);
void	print_board(int **board, char *rules, t_point size);

#endif
