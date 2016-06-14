/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:41:43 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 12:42:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_debug_room(t_env *env)
{
	size_t	i;
	t_head	*cpy;

	cpy = env->head;
	i = 0;
	while (i < cpy->curr)
	{
		ft_putstr(cpy->list[i]->name);
		ft_putstr(" ");
		ft_putnbr(cpy->list[i]->x_coord);
		ft_putstr(" ");
		ft_putnbrendl(cpy->list[i]->y_coord);
		i++;
	}
	if (env->start != NULL)
	{
		ft_putstr("START : ");
		ft_putendl(env->start);
	}
	if (env->end != NULL)
	{
		ft_putstr("END : ");
		ft_putendl(env->end);
	}
}
