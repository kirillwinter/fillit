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
	int	map_size;
	t_elem *head;

	if (argc == 2)
	{
		if ((tet_count = ft_read_file_validate(argv[1])))
		{
			map_size = get_map_size(tet_count);
			head = get_struct_figures(argv[1], map_size);
			fillit(head, map_size);
		}
	}
	return (0);
}
