/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:31:53 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/23 19:31:56 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	size_t	i;
	int		endline;

	i = 0;
	endline = 0;
	while (i < n)
	{
		if (source[i] != '\0' && endline == 0)
			destination[i] = source[i];
		else
		{
			destination[i] = '\0';
			endline = 1;
		}
		i++;
	}
	return (destination);
}
