/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:14:11 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/15 15:14:12 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE		21

# include "libft.h"
# include <stdio.h>

typedef struct		s_elem
{
	char			axis[3][2];
	char			linear[3];
	// int		    	width;
	// int		    	height;
	struct s_elem	*next;
}					t_elem;

typedef struct	s_map
{
	char	*map;
	int		size;
}				t_map;
// struct    s_tetrimino
// {
//     int    width;
//     int    height;
//     char	**axis;
// }        t_tetr;

int		ft_read_file_validate(char *filename);
char	*get_struct_figures(char *filename, int tet_count);
int		get_map_size(int tet_count);
t_elem	*ft_new_fig(char *str, char sym, int x, int y);
// char	*fillit(char *map, char *a, int map_size);
char	*map_creation(int map_size);
int    get_map_size(int tet_count);


#endif
