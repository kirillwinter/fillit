/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:03:39 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/15 17:03:40 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int tet_count;

	tet_count = 0;
	if (argc ==2)
	{
		if ((tet_count = ft_read_file_validate(argv[1])))
		{
			ft_putstr("OK");
			ft_putchar('\n');
			if (!(get_struct_figures(argv[1], tet_count)))
				ft_putstr("GOVNO\n");
		}
		else 
			ft_putstr("KO");
	}
	return (0);
}

// int	main ()
// {
// 	char	map[] = {11, 12, 13, 21, 22, 23, 31, 32, 33};
// 	char	a[] = {12, 22, 31, 32};
// 	char	*map_ptr;
// 	int i;
// 	// int j;
// 	i = 0;
// 	while (i < 9)
// 	{
// 		if ((map_ptr = strpbrk(map, a)))
// 		{
// 			*map_ptr = 'A';
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 9)
// 	{
// 		if (map[i] != 'A')
// 			map[i] = '.';
// 		i++;
// 	}
// 	// ft_putstr(map);
// 	printf("%s", map);
// 	return (0);
// }
