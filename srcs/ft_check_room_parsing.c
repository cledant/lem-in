/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:30:43 by cledant           #+#    #+#             */
/*   Updated: 2016/06/25 13:50:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static inline int	ft_list_check(t_head *e_head, size_t iter)
{
	size_t		i;
	t_graph		*to_check;

	i = iter;
	to_check = e_head->list[i];
	if (ft_strncmp(to_check->name, "L", 1) == 0 ||
			ft_strchr(to_check->name, '-') != NULL ||
				ft_strncmp(to_check->name, "#", 1) == 0)
		return (-1);
	i++;
	while (i < e_head->curr)
	{
		if (to_check->x_coord == e_head->list[i]->x_coord &&
				to_check->y_coord == e_head->list[i]->y_coord)
			return (-1);
		if (ft_strcmp(to_check->name, e_head->list[i]->name) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int					ft_check_room_parsing(t_env *env)
{
	size_t		i;
	t_head		*e_head;

	i = 0;
	e_head = env->head;
	while (i < e_head->curr)
	{
		if (ft_list_check(e_head, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
