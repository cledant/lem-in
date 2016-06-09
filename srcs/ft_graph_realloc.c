/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_realloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:53:06 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 21:16:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_graph_realloc(t_graph *graph)
{
	t_graph		**new;
	size_t		i;

	i = 0;
	if ((new = (t_graph **)malloc(sizeof(t_graph *) * (graph->max + G_SIZE)))
			== NULL)
		return (-1);
	while (i < graph->curr)
	{
		new[i] = graph->next[i];
		i++;
	}
	graph->max = G_SIZE + graph->max;
	free(graph->next);
	graph->next = new;
	return (0);
}
