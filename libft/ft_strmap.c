/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:23:37 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/27 16:23:38 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		arr[i] = f(s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
