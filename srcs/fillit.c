/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:22:56 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/14 18:22:58 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_fig(char *map, t_elem *fig, int i)
{
	map[i + fig->linear[0]] = fig->ch;
	map[i + fig->linear[1]] = fig->ch;
	map[i + fig->linear[2]] = fig->ch;
	map[i] = fig->ch;
}

char	*fillit(char *map, t_elem *fig, int map_size)
{
	int		i;
	int		pos_x;
	int		pos_y;
	
	i = 0;
	while (i < map_size * map_size)
	{
		pos_x = i % map_size;
		pos_y = i / map_size;
		if (pos_y + fig->axis[0][0] < 0)
			i = -fig->axis[0][0] * map_size;
		/* проверяем выход за карту по Х */
		if (fig->width + pos_x > map_size)
		{
			/* идем на следующую строку (уверичиваем у) */
			i = (1 + pos_y) * map_size;
		}
		/* проверяем выход за карту по У */
		if (fig->height_positiv + pos_y > map_size)
		{
			printf("%c!!!!!\n", fig->ch);
			return (0);
			fillit(map, fig, map_size + 1);
		}
		if ((map[i + fig->linear[0]] == '.' && map[i + fig->linear[1]] == '.'
			&& map[i + fig->linear[2]] == '.' && map[i] == '.'))
		{
			put_fig(map, fig, i);
			break ;
		}
		i++;
	}
    return (map);
}
