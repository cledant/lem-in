/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:50:25 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 17:02:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_head_del(t_head **head)
{
	size_t		i;

	i = 0;
	while (i < (*head)->curr)
	{
		ft_graph_del(&((*head)->list[i]));
		i++;
	}
	free((*head)->list);
	(*head)->list = NULL;
	free(*head);
	*head = NULL;
}
