/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:23:47 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/24 18:23:50 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t		i;
	char		*dstptr;
	const char	*srcptr;

	if (destination != source)
	{
		i = 0;
		dstptr = destination;
		srcptr = source;
		while (i < n)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	return (destination);
}
