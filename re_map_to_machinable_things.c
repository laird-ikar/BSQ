/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_map_to_machinable_things.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:52:11 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/29 18:56:50 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "re_map_to_machinable_things.h"

void	re_map_to_machinable_things(int fd, char *rules,
	t_point board_size, int **tab)
{
	char	buffer;
	int		i;
	int		j;

	i = 0;
	while (i < board_size.y)
		tab[i++] = malloc(sizeof(int) * board_size.x);
	i = -1;
	while (read(fd, &buffer, 1) && buffer != '\n')
		continue ;
	while (++i < board_size.y)
	{
		j = 0;
		while (j < board_size.x)
		{
			read(fd, &buffer, 1);
			if (buffer == '\n')
				continue ;
			if (buffer == rules[0])
				tab[i][j] = 0;
			else
				tab[i][j] = 1;
			j++;
		}
	}
}
