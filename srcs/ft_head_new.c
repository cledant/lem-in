/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 17:03:15 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 19:54:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_head		*ft_head_new(size_t size)
{
	t_head		*new;
	t_graph		**g_list;
	size_t		i;

	i = 0;
	if ((new = (t_head *)malloc(sizeof(t_head))) == NULL)
		return (NULL);
	if ((g_list = (t_graph **)malloc(sizeof(t_graph *) * size)) == NULL)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->max = size;
	new->curr = 0;
	new->list = g_list;
	while (i < new->max)
	{
		new->list[i] = NULL;
		i++;
	}
	return (new);
}
