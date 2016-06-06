/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 11:19:39 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 11:25:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph		*ft_seek_node(t_head *head, char *seek)
{
	size_t i;

	i = 0;
	while (i < head->curr)
	{
		if (ft_strcmp(head->list[i]->name, seek) == 0)
			return (head->list[i]);
		i++;
	}
	return (NULL);
}
