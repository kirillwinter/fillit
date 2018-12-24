/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:08:53 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/23 14:09:00 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_map_size(int tet_count)
{
	int	i;

	i = 0;
	if (tet_count < 0)
		return (0);
	while (i * i < tet_count * 4)
		i++;
	return (i);
}

char	*map_creation(int map_size)
{
	char *map;

	if ((map = ft_strnew(map_size * map_size)) == NULL)
		return (0);
	map = ft_memset(map, '.', map_size * map_size);
	return (map);
}

void	print_map(char *map, int map_size)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		ft_putchar(map[i]);
		if (++i % map_size == 0)
			ft_putchar('\n');
	}
}
