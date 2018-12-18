/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:24:56 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/24 16:24:58 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = destination;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (destination);
}
