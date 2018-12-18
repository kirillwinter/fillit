/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:20:59 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 18:21:00 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strdif(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char		*ft_strstr(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (str1 == str2)
		return ((char *)str1);
	while (str1[i])
	{
		if (ft_strdif((char *)&str1[i], (char *)str2) == 0)
			return ((char *)&str1[i]);
		i++;
	}
	return (NULL);
}
