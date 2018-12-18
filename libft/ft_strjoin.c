/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:44:20 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/27 20:44:21 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = -1;
	arr = (char*)malloc(sizeof(*arr) * (len + 1));
	if (arr == NULL)
		return (NULL);
	len = 0;
	while (s1[++i] != '\0')
	{
		arr[len] = s1[i];
		len++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		arr[len] = s2[i];
		len++;
	}
	arr[len] = '\0';
	return (arr);
}
