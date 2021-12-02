/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:43:46 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 19:00:12 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_big_square.h"
#include "get_corners.h"
#include "check_empty_square.h"

void	find_biggest_square(int **board, t_point board_size, char *rules)
{
	int		size;
	t_point	nw;
	t_point	index;

	size = ft_min(board_size.x, board_size.y) + 1;
	while (--size >= 0)
	{
		index.y = -1;
		while (++index.y < board_size.y - size)
		{
			index.x = -1;
			while (++index.x < board_size.x - size)
			{
				nw.x = index.x;
				nw.y = index.y;
				if (is_square_empty(board, nw, size))
				{
					add_square(board, nw, size);
					print_board(board, rules, board_size);
					return ;
				}
			}
		}
	}
	write(1, "No solution\n", 12);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	add_square(int **board, t_point nw, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			board[nw.y + i][nw.x + j] = 2;
			j++;
		}
		i++;
	}
}

void	print_board(int **board, char *rules, t_point size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
			write(1, &rules[board[i][j]], 1);
		write(1, "\n", 1);
	}
}
