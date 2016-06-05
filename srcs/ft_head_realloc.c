/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:53:06 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 13:02:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_head_realloc(t_head *head)
{
	t_graph		**new;
	size_t		i;

	i = 0;
	if ((new = (t_graph **)malloc(sizeof(t_graph *) * (head->max + H_SIZE)))
			== NULL)
		return (-1);
	while (i < head->curr)
	{
		new[i] = head->list[i];
		i++;
	}
	free(head->list);
	head->list = new;
	return (0);
}
