/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:30:05 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/27 16:30:06 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*arr;
	int		i;

	len = 0;
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[len] != '\0')
	{
		len++;
	}
	arr = (char*)malloc(sizeof(*arr) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
