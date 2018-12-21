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

char	*get_mask(int tet_count)
{
	char *mask;

	if ((mask = ft_strnew(tet_count)) == NULL)
		return (NULL);
	mask = ft_memset(mask, '0', tet_count);
	return (mask);
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

void	lin_coord(int map_size, t_elem *fig)
{
	int		i;

	i = -1;
	while (++i < 3)
		fig->linear[i] = fig->axis[i][1] + fig->axis[i][0] * (map_size);
}

char	*get_struct_figures(char *filename, int tet_count)
{
	int		fd;
	char	buf[BUFF_SIZE];
	t_elem	*fig;
	t_elem	*head;
	int		map_size;

	if ((fd = ft_read_file(filename)) == -1)
		return (NULL);
	map_size = get_map_size(tet_count);
	head = NULL;
	while ((read(fd, buf, BUFF_SIZE)))
	{
		buf[20] = '\0';
		fig = ft_new_fig();
		get_coordinates_fig(buf, fig);
		lin_coord(map_size, fig);
		// printf("linear = %s  \n", fig->linear);
		ft_list_push_back(&head, fig);
		
		// fig = fig.next;
		// rez = fillit(map_creation(get_map_size(tet_count)), get_dec_coord(del_bsn(buf)), get_map_size(tet_count)); 
		// ft_new_fig(get_dec_coord(del_bsn(buf)), ch, 1, 1);
		// printf("coord = %s\n\n", arr[nbr_tet]);
	}
	fillit(map_creation(4), fig, 4);
	int i = 0;
	while (head)
	{
		i++;
		// ft_putstr(fig->linear);
		// printf("axis1 = %s  \n", fig->axis[0]);
		// printf("axis2 = %s  \n", fig->axis[1]);
		// printf("axis3 = %s  \n", fig->axis[2]);
		// printf("i = %d  \n", i);
		head = head->next;

	}
	ft_close_file(fd);
	return (0);
}
