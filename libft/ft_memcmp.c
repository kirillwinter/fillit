/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:23:23 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 15:23:25 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*arrptr1;
	unsigned char	*arrptr2;

	arrptr1 = (unsigned char *)arr1;
	arrptr2 = (unsigned char *)arr2;
	i = 0;
	while (i < n)
	{
		if (arrptr1[i] != arrptr2[i])
			return (arrptr1[i] - arrptr2[i]);
		i++;
	}
	return (0);
}
