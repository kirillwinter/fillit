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

void	put_fig(char *pos, t_elem *fig, char ch)
{
	
	*(pos + fig->linear[0]) = ch;
	*(pos + fig->linear[1]) = ch;
	*(pos + fig->linear[2]) = ch;
	*(pos) = ch;
}

int		fix_fig_on_map(char *map, t_elem *fig, int map_size, int *i)
{
	int		pos_x;
	int		pos_y;
	
	pos_x = *i % map_size;
	pos_y = *i / map_size;
	// fig->touch = 1;
	if (pos_y + fig->axis[0][0] < 0)
		*i = -fig->axis[0][0] * map_size;
	if (fig->width > map_size)
		return (-1);
	/* проверяем выход за карту по Х */
	if (fig->width + pos_x > map_size)
	{
		/* идем на следующую строку (уверичиваем у) */
		*i = (1 + pos_y) * map_size;
		return (0);
	}
	/* проверяем выход за карту по У */
	if (fig->height_positiv + pos_y >= map_size)
		return (-1);
	if ((map[*i + fig->linear[0]] == '.' && map[*i + fig->linear[1]] == '.'
		&& map[*i + fig->linear[2]] == '.' && map[*i] == '.'))
	{
		put_fig(map + *i, fig, fig->ch);
		fig->used = 1;
		return (1);
	}
	else
		(*i)++;
	// put_fig(map + i, fig, '.');
    return (0);
}

int		recurs_fillit(char *map, t_elem *head, int map_size)
{
	int	i;
	int	res;
	char flag;
	t_elem *fig;

	flag = 0;
	fig = head;
	while (fig)
	{
		if (!fig->used)
		{
			flag = 1;
			i = 0;
			while (i < map_size * map_size)
			{
				if((res = fix_fig_on_map(map, fig, map_size, &i)) == -1)
					break ;
				else if (res == 0)
					continue ;
				else
				{
					if (recurs_fillit(map, head, map_size))
						return (1);
					put_fig(map + i, fig, '.');
					fig->used = 0;
				}
				i++;
			}
		}
		fig = fig->next;
	}
	
	
	return (flag == 0);
}
