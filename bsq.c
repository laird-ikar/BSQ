/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:58:15 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 09:35:12 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "check_map_rules.h"
#include "re_map_to_machinable_things.h"
#include "find_big_square.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	char	rules[3];
	t_point	board_size;
	int		**board;
	int		i;

	board = NULL;
	board_size.x = 0;
	board_size.y = 0;
	if (argc < 2)
	{
		from_stdin(rules, board_size, board);
	}
	i = 0;
	while (argv[++i])
	{
		if (i > 1)
			write(1, "\n\n----- next -----\n\n", 20);
		from_file(rules, board_size, board, argv[i]);
	}
}

void	from_stdin(char rules[3], t_point board_size, int **board)
{
	char	buffer;
	int		fd;

	fd = open("temp", O_RDWR | O_TRUNC);
	while (read(0, &buffer, 1) && buffer != 13)
	{
		write(fd, &buffer, 1);
	}
	close(fd);
	write(1, "\n\n", 2);
	if (check_map_rules("temp", rules, &board_size) < 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	else
	{
		print_separator(board_size.y);
		board = malloc(sizeof(int *) * board_size.y);
		fd = open("temp", O_RDONLY);
		re_map_to_machinable_things(fd, rules, board_size, board);
		close(fd);
		find_biggest_square(board, board_size, rules);
		free(board);
	}
}

void	from_file(char rules[3], t_point board_size,
					int **board, char *map_file)
{
	int		fd;

	if (check_map_rules(map_file, rules, &board_size) < 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	else
	{
		board = malloc(sizeof(int *) * board_size.y);
		fd = open(map_file, O_RDONLY);
		re_map_to_machinable_things(fd, rules, board_size, board);
		close(fd);
		find_biggest_square(board, board_size, rules);
		free(board);
	}
}

void	print_separator(int y)
{
	int	i;

	i = -1;
	while (++i < y)
		write(1, "-", 1);
	write(1, "Solution :", 10);
	write(1, "\n\n", 2);
}
