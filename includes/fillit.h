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

typedef struct	s_elem
{
	char			axis[3][2];
	char			linear[3];
	int				height_positiv;
	int				width;
	char			ch;
	int				used;
	struct s_elem	*next;
}				t_elem;

int				ft_read_file_validate(char *filename);
t_elem			*get_struct_figures(char *filename, int map_size);
int				get_map_size(int tet_count);
t_elem			*ft_new_fig();
void			del_list(t_elem **alst);
char			*map_creation(int map_size);
int				get_map_size(int tet_count);
void			ft_list_push_back(t_elem **begin_list, t_elem *new);
int				recurs_fillit(char *map, t_elem *head, int map_size);
int				fix_fig_on_map(char *map, t_elem *fig, int map_size, int *i);
void			fillit(t_elem *head, int map_size);
void			print_map(char *map, int map_size);
void			get_positiv_height(t_elem *fig);
void			get_width(t_elem *fig);
void			get_coordinates_fig(char *buf, t_elem *fig);
void			get_lin_coord(int map_size, t_elem *fig);

#endif
