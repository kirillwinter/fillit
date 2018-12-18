/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:43:46 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/23 18:43:48 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*arr;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	arr = NULL;
	arr = (char*)malloc(sizeof(*arr) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
