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

t_elem	*get_struct_figures(char *filename,	int map_size)
{
	int		fd;
	char	buf[BUFF_SIZE];
	t_elem	*fig;
	t_elem	*head;
	int		i;

	if ((fd = ft_read_file(filename)) == -1)
		return (NULL);
	head = NULL;
	i = -1;
	while ((read(fd, buf, BUFF_SIZE)))
	{
		buf[20] = '\0';
		if (!(fig = ft_new_fig(buf, map_size, ++i)))
			return (NULL);
		ft_list_push_back(&head, fig);
	}
	ft_close_file(fd);
	return (head);
}
