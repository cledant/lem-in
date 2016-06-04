/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:16:40 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 19:53:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_graph_del(t_graph **graph)
{
	size_t	i;

	i = 0;
	if ((*graph)->name != NULL)
		ft_strdel(&((*graph)->name));
	while (i < (*graph)->curr)
	{
		(*graph)->next[i] = NULL;
		i++;
	}
	free(*graph);
	*graph = NULL;
}
