/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:38:36 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 16:38:37 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	size_t len;
	size_t i;

	i = 0;
	len = 0;
	while (destination[len] != '\0')
	{
		len++;
	}
	while (append[i] != '\0' && i < n)
	{
		destination[len] = append[i];
		len++;
		i++;
	}
	destination[len] = '\0';
	return (destination);
}
