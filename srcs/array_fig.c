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

// int		get_start_pos(char *buf, int map_size)
// {
// 	int	i;
// 	int	j;
// 	int	flag;

// 	i = 0;
// 	j = 0;
// 	flag = 0;
// 	while (j <= map_size)
// 	{
// 		while (i <= map_size * map_size)
// 		{
// 			if (buf[i] == '#')
// 			{
// 				flag = 1;
// 				break ;
// 			}
// 			i += map_size;
// 		}
// 		if (flag)
// 			break ;
// 		j++;
// 		i = j;
// 	}
// 	return (i);
// }

// char	*get_coordinates_fig(char *buf, int map_size)
// {
// 	char	*arr;
// 	int		i;
// 	int		nb;
// 	int		start_pos;

// 	i = 0;
// 	nb = 0;
// 	arr = (char*)malloc(4 * sizeof(char));
// 	start_pos = -get_start_pos(buf, map_size);
// 	i = 0;
// 	while (buf[i] != '\0')
// 	{
// 		if (buf[i] == '#' && i != -start_pos)
// 		{
// 			arr[nb] = start_pos + i;
// 			nb++;
// 		}
// 		i++;
// 	}
// 	arr[nb] = '\0';
// 	return (arr);
// }

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

// char	*get_mask(int tet_count)
// {
// 	char *mask;

// 	if ((mask = ft_strnew(tet_count)) == NULL)
// 		return (NULL);
// 	mask = ft_memset(mask, '0', tet_count);
// 	return (mask);
// }

// char	**change_coord(char *a)
// {
// 	char	**b;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	if (!(b = (char **)malloc(3 * sizeof(char *)) || \
// 		(b[0] = ft_strnew(4)) || (b[1] = ft_strnew(4))))
// 		return (NULL);
// 	while (a[++i] != '\0')
// 	{
// 		if (a[i] < 0)
// 		{
// 			b[0][i] = a[i] % 4 + 4;        // для х
// 			b[1][i] = a[i] / 4 - 1;    // для у
// 		}
// 		else
// 		{
// 			b[0][i] = a[i] % 4;            // для х
// 			b[1][i] = a[i] / 4;        // для у
// 		}
// 	}
// 	b[0][j] = 0;
// 	b[1][j] = 0;
// 	b[2] = '\0';
// 	return (b);
// }

char	*get_dec_coord(char *a)
{
	char	*b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	b = ft_strnew(4);
	while (i < 16)
	{
		if (i < 4 && a[i] == '#')
			b[j++] = i + 11;
		if (i > 3 && i < 8 && a[i] == '#')
			b[j++] = i + 17;
		if (i > 7 && i < 12 && a[i] == '#')
			b[j++] = i + 23;
		if (i > 11 && a[i] == '#')
			b[j++] = i + 29;
		i++;
	}
	b[j] = '\0';
	return (b);	
}

char	*get_struct_figures(char *filename, int tet_count)
{
	int		fd;
	int		ret;
	char	*buf;
	char	ch = 'A';
	char	*rez;


	if ((fd = ft_read_file(filename)) == -1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		rez = fillit(map_creation(get_map_size(tet_count)), get_dec_coord(del_bsn(buf)), get_map_size(tet_count)); 

		// ft_new_fig(get_dec_coord(del_bsn(buf)), ch, 1, 1);
		ch++;
		// printf("coord = %s\n\n", arr[nbr_tet]);
	}
	ft_putstr(rez);
	free(buf);
	ft_close_file(fd);
	return (NULL);
}
