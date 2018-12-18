/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:01:48 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/26 20:01:51 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			sign;

	i = ft_spaces(str);
	nb = 0;
	sign = 1;
	if (str[i] == '-' && (str[i + 1] <= '9' && str[i + 1] >= '0'))
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] <= '9' && str[i + 1] >= '0'))
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (nb < 0)
			return (-((sign + 1) / 2));
	}
	return (sign * nb);
}
