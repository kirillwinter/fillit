/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:59:32 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/20 17:59:33 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_elem	*ft_new_fig()
{
	t_elem	*elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_elem **alst, t_elem *new)
{
	t_elem *list;

	if (new != NULL)
	{
		if (alst && *alst)
		{
			list = *alst;
			while (list != NULL)
			{
				if (list->next)
					list = list->next;
				else
				{
					list->next = new;
					break ;
				}
			}
		}
		else
			*alst = new;
	}
}
