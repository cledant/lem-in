/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:16:40 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 13:11:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_graph_del(t_graph **graph)
{
	size_t	i;

	i = 0;
	if ((*graph)->name != NULL)
		ft_strdel(&((*graph)->name));
	free((*graph)->next);
	(*graph)->next = NULL;
	free(*graph);
	*graph = NULL;
}
