/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:55:59 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/24 13:56:00 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (destination[len] != '\0')
	{
		len++;
	}
	while (append[i] != '\0')
	{
		destination[len] = append[i];
		len++;
		i++;
	}
	destination[len] = '\0';
	return (destination);
}
