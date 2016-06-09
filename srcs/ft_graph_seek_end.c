/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_seek_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:32:00 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 22:48:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static inline int	ft_step(t_head *old, t_head *new, t_env *env, size_t val[2])
{
	if ((old->list[val[0]]->next[val[1]]->hist =
			ft_strjoin_cat(old->list[val[0]]->hist,
				old->list[val[0]]->next[val[1]]->name, ' ')) == NULL)
		return (-1);
	if (ft_strcmp(old->list[val[0]]->next[val[1]]->name, env->end) == 0)
	{
		env->path = old->list[val[0]]->next[val[1]]->hist;
		return (-1);
	}
	if (new->curr == new->max)
		if (ft_head_realloc(new) == -1)
			return (-1);
	new->list[new->curr] = old->list[val[0]]->next[val[1]];
	new->curr++;
	return (0);
}

void				ft_graph_seek_end(t_head *old, t_head *new, t_env *env)
{
	size_t		val[2];

	val[0] = 0;
	val[1] = 0;
	while (val[0] < old->curr)
	{
		while (val[1] < old->list[val[0]]->curr)
		{
			if (old->list[val[0]]->next[val[1]]->hist == NULL)
				if (ft_step(old, new, env, val) == -1)
					return ;
			val[1]++;
		}
		val[0]++;
		val[1] = 0;
	}
	if (new->curr == 0)
		return ;
	old->curr = 0;
	ft_graph_seek_end(new, old, env);
}
