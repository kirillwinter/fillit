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
			if (!(get_array_figures(argv[1], tet_count)))
				ft_putstr("GOVNO");
		}
		else 
			ft_putstr("KO");
	}
	return (0);
}
