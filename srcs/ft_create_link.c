/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:48:59 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 18:25:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_create_link(t_env *env, char	*from, char *to)
{
	t_graph		*n_from;
	t_graph		*n_to;

	if ((n_from = ft_seek_node(env->head, from)) == NULL)
		return (-1);
	if ((n_to = ft_seek_node(env->head, to)) == NULL)
		return (-1);
	if (n_from->curr == n_from->max)
		if (ft_graph_realloc(n_from) == -1)
			return (-1);
	n_from->next[n_from->curr] = n_to;
	n_from->curr++;
	if (n_to->curr == n_to->max)
		if (ft_graph_realloc(n_to) == -1)
			return (-1);
	n_to->next[n_to->curr] = n_from;
	n_to->curr++;
	return (0);
}
