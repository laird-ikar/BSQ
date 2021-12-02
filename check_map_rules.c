/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:58:20 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 09:24:50 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "check_map_rules.h"

int	check_map_rules(char *map_file, char rules[3], t_point *board_size)
{
	int		fd;
	char	buffer;
	int		size;
	int		check_content;

	size = get_params_size(map_file);
	if (!size)
		return (-1);
	fd = open(map_file, O_RDONLY);
	board_size->y = get_nb_lines(fd, size);
	size = 0;
	while (read(fd, &buffer, 1) && buffer != '\n')
		rules[size++] = buffer;
	check_content = check_map_content(rules, fd, buffer, board_size);
	close(fd);
	if (check_content != board_size->y || check_content < 0
		|| rules[0] == rules[1] || rules[1] == rules[2] || rules[0] == rules[2]
		|| board_size->x < 1 || board_size->y < 1)
		return (-1);
	return (0);
}

int	check_map_content(char *rules, int fd, char buffer, t_point *board_size)
{
	t_point	size;
	int		count;

	count = 0;
	size.y = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			if (size.y == 0)
				size.x = count;
			if (size.y > 0 && count != size.x)
				return (-1);
			size.y++;
			count = 0;
		}
		else
		{
			if (!is_in_rules(buffer, rules) || buffer == rules[2])
				return (-1);
			count++;
		}
	}
	board_size->x = size.x;
	return (size.y);
}

int	get_nb_lines(int fd, int size)
{
	char	buffer;
	int		nb_lines;
	int		i;

	nb_lines = 0;
	i = 0;
	while (i < size - 3)
	{
		read(fd, &buffer, 1);
		nb_lines *= 10;
		nb_lines += buffer - '0';
		i++;
	}
	return (nb_lines);
}

int	get_params_size(char *map_file)
{
	int		fd;
	char	buffer;
	int		size;

	size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error while opening file\n", 25);
		return (0);
	}
	while (read(fd, &buffer, 1) && buffer != '\n')
	{
		size++;
	}
	close(fd);
	return (size);
}

int	is_in_rules(char slot, char *rules)
{
	int	i;

	i = -1;
	while (rules[++i])
		if (slot == rules[i])
			return (1);
	return (0);
}
