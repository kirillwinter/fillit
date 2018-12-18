/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:02:49 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 18:02:50 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	while (len >= 0)
	{
		if (str[len] == c)
		{
			return ((char *)&str[len]);
		}
		len--;
	}
	return (NULL);
}
