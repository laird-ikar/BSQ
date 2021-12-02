/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:41:59 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:08:25 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "check_empty_square.h"

int	is_square_empty(int **board, t_point nw, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (board[nw.y + i][nw.x + j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
