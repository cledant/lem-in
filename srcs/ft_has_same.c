/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_same.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:40:25 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 10:40:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_has_same(char *norm, char *inv, t_list *begin, t_list *curr)
{
	while (begin != NULL && begin != curr)
	{
		if (ft_strncmp(begin->content, "#", 1) != 0)
		{
			if (strcmp(begin->content, norm) == 0)
				return (1);
			if (strcmp(begin->content, inv) == 0)
				return (1);
		}
		begin = begin->next;
	}
	return (0);
}
