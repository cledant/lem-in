/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 11:07:40 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 17:58:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				ft_room_list(t_env *env, t_list **list)
{
	while (*list != NULL)
	{
//		ft_putendl((*list)->content);
		if (ft_strncmp((*list)->content, "#", 1) == 0)
		{
			if (ft_strncmp((*list)->content, "##", 2) == 0)
			{
				if (ft_command(env, list) == -1)
					return (-1);
			}
		}
		else if (ft_part_nb((*list)->content, ' ') == 3)
		{
			if (ft_create_new_room(env, (*list)->content) == -1)
				return (-1);
		}
		else
			return (0);
		*list = (*list)->next;
	}
	return (-1);
}
