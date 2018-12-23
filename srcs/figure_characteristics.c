/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_characteristics.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:43:14 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/23 13:43:16 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_start_pos(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= 4)
	{
		while (i < 20)
		{
			if (buf[i] == '#')
				return (i);
			i += 5;
		}
		j++;
		i = j;
	}
	return (i);
}

void	get_coordinates_fig(char *buf, t_elem *fig)
{
	int		i;
	int		nb;
	int		start_pos;

	i = 0;
	nb = 0;
	start_pos = get_start_pos(buf);
	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && i != start_pos)
		{
			if (i < start_pos)
			{
				fig->axis[nb][0] = (i - start_pos) / 5 - 1;
				fig->axis[nb][1] = (i - start_pos) % 5 + 5;
			}
			else
			{
				fig->axis[nb][0] = (i - start_pos) / 5;
				fig->axis[nb][1] = (i - start_pos) % 5;
			}
			nb++;
		}
		i++;
	}
}

void	get_lin_coord(int map_size, t_elem *fig)
{
	int		i;

	i = -1;
	while (++i < 3)
		fig->linear[i] = fig->axis[i][1] + fig->axis[i][0] * (map_size);
}

void	get_positiv_height(t_elem *fig)
{
	int max;

	max = fig->axis[0][0];
	if (fig->axis[1][0] > max)
		max = fig->axis[1][0];
	if (fig->axis[2][0] > max)
		max = fig->axis[2][0];
	fig->height_positiv = max;
}

void	get_width(t_elem *fig)
{
	int max;

	max = fig->axis[0][1];
	if (fig->axis[1][1] > max)
		max = fig->axis[1][1];
	if (fig->axis[2][1] > max)
		max = fig->axis[2][1];
	fig->width = max;
}
