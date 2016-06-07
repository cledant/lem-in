/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_seek_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:32:00 by cledant           #+#    #+#             */
/*   Updated: 2016/06/07 13:29:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_graph_seek_end(t_head *old, t_head *new, t_env *env)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < old->curr)
	{
		while (j < old->list[i]->curr)
		{
			if (old->list[i]->next[j]->hist == NULL)
			{
				if ((old->list[i]->next[j]->hist =
							ft_strjoin_cat(old->list[i]->hist,
								old->list[i]->next[j]->name, ' ')) == NULL)
					return ;
				if (ft_strcmp(old->list[i]->next[j]->name, env->end) == 0)
				{
					env->path = old->list[i]->next[j]->hist;
					return ;
				}
				if (new->curr == new->max)
					if (ft_head_realloc(new) == -1)
						return ;
				new->list[new->curr] = old->list[i]->next[j];
				new->curr++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (new->curr == 0)
		return ;
	old->curr = 0;
	ft_graph_seek_end(new, old, env);
}
