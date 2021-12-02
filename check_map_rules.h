/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rules.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:43:25 by bguyot            #+#    #+#             */
/*   Updated: 2021/11/30 07:56:23 by bdehais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_RULES_H
# define CHECK_MAP_RULES_H

# ifndef T_POINT
#  define T_POINT

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
# endif

int		check_map_rules(char *map_file, char rules[3], t_point *board_size);
int		get_params_size(char *map_file);
int		is_in_rules(char slot, char *rules);
int		get_nb_lines(int fd, int size);
int		check_map_content(char *rules, int fd, char buffer,
			t_point *board_size);

#endif
