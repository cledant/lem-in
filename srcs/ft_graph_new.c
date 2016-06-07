/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:22:09 by cledant           #+#    #+#             */
/*   Updated: 2016/06/07 09:52:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph		*ft_graph_new(size_t size)
{
	t_graph		*new;
	t_graph		**g_list;
	size_t		i;

	i = 0;
	if ((new = (t_graph *)malloc(sizeof(t_graph))) == NULL)
		return (NULL);
	if ((g_list = (t_graph **)malloc(sizeof(t_graph *) * size)) == NULL)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->name = NULL;
	new->hist = NULL;
	new->x_coord = 0;
	new->y_coord = 0;
	new->max = size;
	new->curr = 0;
	new->next = g_list;
	while (i < new->max)
	{
		new->next[i] = NULL;
		i++;
	}
	return (new);
}
