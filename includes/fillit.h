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

int		ft_read_file_validate(char *filename);
int		get_array_figures(char *filename, int tet_count);

#endif
