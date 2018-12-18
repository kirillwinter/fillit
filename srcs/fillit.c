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

int map_creation(int tet_count) // ВСТАВИТЬ ИСПРАВЛЕННУЮ ВЕРСИЮ 
{
	int map_size;
	char *map;

	map_size = (ft_sqrt(tet_count * 4) + 1);
	if ((map = ft_strnew(map_size * map_size)) == NULL)
		return (0);
	map = ft_memset(map, '.', map_size * map_size);
	return (1);
}

int fillit_map(char *map, char *arr, int map_size, char *tf)
{
	int i;
	int	kr;
	char ch = 'A';
	char *map_ptr;

	kr = 0;
	map_ptr = map;
	while (map)
	{
		if (map[arr[kr]] != '.')
		{
			map_ptr = ft_memset(map_ptr, '.', map_size * map_size);
			map = map + map_size;
		}
		else
		{
			map[arr[kr]] == ch;
			kr++;
		}
		
	}
}

char	*coordinates_of_figures(char *buf)
{
	char	*arr;
	int		i;
	int		nb;
	int 	j;
	int		start_pos;
	int		flag = 0;

	j = 0;
	i = 0;
	nb = 0;
	arr = (char*)malloc(4 * sizeof(char));
	while (j < 5)
	{
		while (i < 20)
		{
			if (buf[i] == '#')
			{
				flag = 1;
				break;
			}
			i += 4; 
		}
		if (flag)
			break;
		j++;
		i = j;
	}
	start_pos = -i;
	i = 0;
	// arr[0] = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && i != -start_pos)
		{
			arr[nb] = start_pos + i;
			nb++;
		}
		i++;
	}
	arr[nb] = '\0';
	return (arr);
}

char	*del_bsn(char *buf)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	arr = (char*)malloc(sizeof(char *) * 17);
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n')
		{
			arr[j] = buf[i];
			i++;
			j++;
		}
		else
			i++;
	}
	arr[j] = '\0';
	return (arr);
}

int		get_array_figures(char *filename, int tet_count)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	char	**arr;
	int		nbr_tet;

	nbr_tet = 0;
	if ((fd = ft_read_file(filename)) == -1)
		return (0);
	if (!(arr = (char **)malloc((tet_count + 1) * sizeof(char *))))
		return (0);
	// if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	// 		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(arr[nbr_tet] = ft_strdup(coordinates_of_figures(del_bsn(buf)))))
			return (0);
	
		// ft_putstr(arr[nbr_tet]);
		nbr_tet++;
	}
	ft_close_file(fd);
	return (1);
}
