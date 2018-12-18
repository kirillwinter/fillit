/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:53:16 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/24 18:53:18 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	i = 0;
	dstptr = (unsigned char*)destination;
	srcptr = (unsigned char*)source;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		if (srcptr[i] == (unsigned char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
