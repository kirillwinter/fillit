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

char	*get_mask(int tet_count)
{
	char *mask;

	if ((mask = ft_strnew(tet_count)) == NULL)
		return (NULL);
	mask = ft_memset(mask, '0', tet_count);
	return (mask);
}

char	*get_struct_figures(char *filename, int tet_count)
{
	int		fd;
	char	buf[BUFF_SIZE];
	t_elem	*fig;
	t_elem	*head;
	int		map_size;
	char 	*map;
	int		i;

	if ((fd = ft_read_file(filename)) == -1)
		return (NULL);
	map_size = get_map_size(tet_count);
	head = NULL;
	map = map_creation(4);
	i = -1;
	while ((read(fd, buf, BUFF_SIZE)))
	{
		buf[20] = '\0';
		fig = ft_new_fig(buf, map_size, ++i);
	
		map = fillit(map, fig, 4);
		ft_list_push_back(&head, fig);
	}
	// int i = 0;
	// while (head)
	// {
	// 	// map = fillit(map, fig, 4);
	// 	i++;
	// 	// ft_putstr(fig->linear);
	// 	// printf("axis1 = %s  \n", fig->axis[0]);
	// 	// printf("axis2 = %s  \n", fig->axis[1]);
	// 	// printf("axis3 = %s  \n", fig->axis[2]);
	// 	// printf("i = %d  \n", i);
	// 	head = head->next;

	// }
	// map = fillit(map, head->next, 4);
	print_map(map);
	ft_close_file(fd);
	ft_putchar('\n');
	return (0);
}
