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

int    get_map_size(int tet_count)
{
	int    i;
	
	i = 0;
	if (tet_count < 0)
		return (0);
	while (i * i < tet_count * 4 && i <= 46340)
		i++;
	printf("map_size =  %d\n\n", i);
	i = 4; // УДАЛИТЬ СТРОКУ
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

// char	*fillit(char *map, char *a, int map_size)
// {
// 	char	*map_ptr;
// 	int i;
// 	map_size = 4; // !!!
// 	// int j;
// 	i = 0;
// 	while (i < map_size * map_size)
// 	{
// 		if ((map_ptr = strpbrk(map, a))) // ИСПОЛЬЗОВАТЬ ФУНКЦИЮ ИЗ ЛИБЫ!!!!!!!
// 		{
// 			*map_ptr = 'A';
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < map_size * map_size)
// 	{
// 		if (map[i] != 'A')
// 			map[i] = '.';
// 		i++;
// 	}
// 	// ft_putstr(map);
// 	// printf("%s", map);
// 	return (map);
// }

void	print_map(char *map)
{
	int i;
	int map_size;

	i = 0;
	map_size = ft_sqrt(ft_strlen(map));
	printf("map_size_print = %d  \n", map_size);
	while (map[i] != '\0')
	{
		ft_putchar(map[i]);
		if (++i % map_size == 0)
			ft_putchar('\n');
	}
}


char	*fillit(char *map, t_elem *fig, int map_size)
{
	int		i;
	static char	ch = 'A' - 1;
	int		shift_x;
	
	i = 0;
	ch++;
	while (i < map_size * map_size)
	{
		shift_x = i % map_size;
		if (fig->axis[0][0] < 0)
			i = -fig->axis[0][0] * map_size;
		/* проверяем выход за карту по Х */
		if (fig->axis[0][1] + shift_x > map_size || fig->axis[1][1] + shift_x > map_size || fig->axis[2][1] + shift_x > map_size || i / map_size >= 1)
		{
			/* возвразаем координаты Х */
			// fig->axis[0][1] = fig->axis[0][1] - shift_x;
			// fig->axis[1][1] = fig->axis[1][1] - shift_x;
			// fig->axis[2][1] = fig->axis[2][1] - shift_x;
			/* идем на следующую строку (уверичиваем у) */
			fig->axis[0][0]++;
			fig->axis[1][0]++;
			fig->axis[2][0]++;
		}
		/* проверяем выход за карту по У */
		if (fig->axis[0][0] >= map_size || fig->axis[1][0] >= map_size || fig->axis[2][0] >= map_size)
		{
			map = map_creation(map_size + 1);
			printf("%c!!!!!\n", ch);
			fillit(map, fig, map_size + 1);
		}
		if ((map[i + fig->linear[0]] == '.' && map[i + fig->linear[1]] == '.' && map[i + fig->linear[2]] == '.' && map[i] == '.') 
			&& (fig->axis[0][1] + shift_x < map_size || fig->axis[1][1] + shift_x < map_size || fig->axis[2][1] + shift_x < map_size))
		{
			map[i + fig->linear[0]] = ch;
			map[i + fig->linear[1]] = ch;
			map[i + fig->linear[2]] = ch;
			map[i] = ch;
			break ;
		}
		i++;
	}
	// printf("map = %s\n", map);
	// ft_putstr(map);
	ft_putchar('\n');
	// print_map(map, map_size);
    return (map);
}
