/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:12:48 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 09:00:22 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

void	from_stdin(char rules[3], t_point board_size, int **board);
void	from_file(char rules[3], t_point board_size,
			int **board, char *map_file);
void	print_separator(int y);

#endif
