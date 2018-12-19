/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:24:04 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/19 13:24:06 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_start_pos(char *buf, int map_size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (j <= map_size)
	{
		while (i <= map_size * map_size)
		{
			if (buf[i] == '#')
			{
				flag = 1;
				break ;
			}
			i += map_size;
		}
		if (flag)
			break ;
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
			arr[nb] = '0' + start_pos + i;
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

char	*check_fig(char *arr, int tet_count)
{
	if (tet_count == 1 && (arr[0] == 1 && arr[1] == 4 && arr[2] == 5))
	{
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
	}
	if (tet_count == 2)
	{
		
	}
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
		if (!(arr[nbr_tet] = ft_strdup(get_coordinates_fig(del_bsn(buf), get_map_size(tet_count)))))
		/* нужна функция удаления всех массивов при неудачном выделении памяти */
			return (NULL);
		printf("coord = %s\n\n", arr[nbr_tet]);
		nbr_tet++;
	}
	arr[nbr_tet] = NULL;
	free(buf);
	ft_close_file(fd);
	return (arr);
}
