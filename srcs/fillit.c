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
	return (map_size);
}

// int fillit_map(char *map, char *arr, int map_size, char *mask)
// {
// 	int i;
// 	int	kr;
// 	char ch = 'A';
// 	char *map_ptr;

// 	kr = 0;
// 	map_ptr = map;
// 	while (map)
// 	{
// 		if (map[arr[kr]] != '.')
// 		{
// 			map_ptr = ft_memset(map_ptr, '.', map_size * map_size);
// 			map++;
// 		}
// 		else
// 		{
// 			map[arr[kr]] == ch;
// 			kr++;
// 		}
		
// 	}
// }

int		get_start_pos(char *buf, int map_size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (j < 5)
	{
		while (i < 20)
		{
			if (buf[i] == '#')
			{
				flag = 1;
				break;
			}
			i += map_size; 
		}
		if (flag)
			break;
		j++;
		i = j;
	}
	return (i);
}

char	*get_coordinates_fig(char *buf, int map_size)
{
	char	*arr;
	int		i;
	int		nb;
	int		start_pos;

	i = 0;
	nb = 0;
	arr = (char*)malloc(4 * sizeof(char));
	start_pos = -get_start_pos(buf, map_size);
	i = 0;
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

char	*get_mask(int tet_count)
{
	char *mask;

	if ((mask = ft_strnew(tet_count)) == NULL)
		return (NULL);
	mask = ft_memset(mask, '0', tet_count);
	return (mask);
}

char	**get_array_figures(char *filename, int tet_count)
{
	int		fd;
	int		ret;
	char	*buf;
	char	**arr;
	int		nbr_tet;

	nbr_tet = 0;
	if ((fd = ft_read_file(filename)) == -1)
		return (NULL);
	if (!(arr = (char **)malloc((tet_count + 1) * sizeof(char *))))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(arr[nbr_tet] = ft_strdup(get_coordinates_fig(del_bsn(buf))))) 
		//  нужна функция удаления всех массивов при неудачном выделении памяти
			return (NULL);
		nbr_tet++;
	}
	arr[nbr_tet] = NULL;
	free(buf);
	ft_close_file(fd);
	return (arr);
}
