/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:20 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 16:47:22 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *append, size_t size)
{
	char		*dstptr;
	const char	*appptr;
	size_t		n;
	size_t		dlen;

	dstptr = destination;
	appptr = append;
	n = size;
	while (n-- != 0 && *dstptr != '\0')
		dstptr++;
	dlen = dstptr - destination;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen((char *)appptr));
	while (*appptr != '\0')
	{
		if (n != 1)
		{
			*dstptr++ = *appptr;
			n--;
		}
		appptr++;
	}
	*dstptr = '\0';
	return (dlen + (appptr - append));
}
