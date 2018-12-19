/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:00:48 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/15 15:00:49 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	character_replacement(char *buf)
{
	int			i;
	static char	ch = 'A';

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			buf[i] = ch;
		i++;
	}
	ch++;
}

int		validate_touch(char *buf, int i)
{
	int valid;

	valid = 0;
	if (buf[i] == buf[i + 1])
		valid++;
	if (buf[i] == buf[i - 1])
		valid++;
	if (buf[i] == buf[i + 5])
		valid++;
	if (buf[i] == buf[i - 5])
		valid++;
	return (valid);
}

int		validate_tetriminos(char *buf, int ret)
{
	int i;
	int grid_coun;
	int bsn_coun;
	int val;

	i = -1;
	grid_coun = 0;
	bsn_coun = 0;
	val = 0;
	while (++i < ret)
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
		{
			grid_coun++;
			if (!(val += validate_touch(buf, i)))
				return (0);
		}
		bsn_coun += (buf[i] == '\n') ? 1 : 0;
	}
	if ((buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n'
		|| buf[20] != '\n') || (grid_coun != 4 || bsn_coun != 5) || (val < 5))
		return (0);
	return (1);
}

int		ft_read_file_validate(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	int		tet_count;

	tet_count = 0;
	if ((fd = ft_read_file(filename)) == -1)
		return (0);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (validate_tetriminos(buf, ret) == 0)
		{
			ft_putstr("error");
			return (0);
		}
		tet_count++;
	}
	free(buf);
	ft_close_file(fd);
	return (tet_count);
}
