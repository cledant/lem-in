/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:43:33 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 12:43:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_debug_link(t_env *env)
{
	size_t	i;
	size_t	j;
	t_head	*cpy;

	cpy = env->head;
	i = 0;
	j = 0;
	while (i < cpy->curr)
	{
		ft_putendl(cpy->list[i]->name);
		while (j < cpy->list[i]->curr)
		{
			ft_putstr("LINK TO : ");
			ft_putendl(cpy->list[i]->next[j]->name);
			j++;
		}
		j = 0;
		i++;
	}
}
