/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:30:23 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/24 19:30:24 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	if (destination != source)
	{
		i = n;
		dstptr = (unsigned char *)destination;
		srcptr = (unsigned char *)source;
		if (srcptr < dstptr)
		{
			while (i-- > 0)
				dstptr[i] = srcptr[i];
		}
		else
			ft_memcpy(destination, source, n);
	}
	return (destination);
}
