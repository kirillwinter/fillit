/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:09:49 by wballaba          #+#    #+#             */
/*   Updated: 2018/11/27 21:09:51 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_startpos(char const *s)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		start++;
	}
	return (start);
}

static int	ft_endpos(char const *s, int len)
{
	int end;

	end = 0;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		end++;
		len--;
	}
	return (end);
}

static int	ft_validate_ft_strtrim(char const *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	if (s[i] == '\0' && i != 0)
		return (2);
	return (1);
}

static char	*ft_empty_str(void)
{
	char	*arr;

	arr = (char*)malloc(sizeof(*arr) * (1));
	arr[0] = '\0';
	return (arr);
}

char		*ft_strtrim(char const *s)
{
	char	*arr;
	int		i;
	int		len;
	int		start;
	int		end;

	i = -1;
	if (ft_validate_ft_strtrim(s) == 0)
		return (NULL);
	if (ft_validate_ft_strtrim(s) == 2)
		return (ft_empty_str());
	len = ft_strlen((char *)s);
	start = ft_startpos(s);
	end = ft_endpos(s, len - 1);
	len = len - start - end;
	arr = (char*)malloc(sizeof(*arr) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (++i < len)
	{
		arr[i] = s[start];
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
