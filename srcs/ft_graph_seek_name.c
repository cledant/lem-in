/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_seek_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:20:52 by cledant           #+#    #+#             */
/*   Updated: 2016/06/07 10:31:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph		*ft_graph_seek_name(t_head *head, char *name)
{
	size_t	i;

	i = 0;
	while (i < head->curr)
	{
		if (ft_strcmp(head->list[i]->name, name) == 0)
			return (head->list[i]);
		i++;
	}
	return (NULL);
}
