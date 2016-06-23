/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_connect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 19:28:58 by cledant           #+#    #+#             */
/*   Updated: 2016/06/23 13:25:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				ft_room_connect(t_env *env, t_list **list, t_list *cpy_list)
{
	while (*list != NULL)
	{
		if (ft_strncmp((*list)->content, "#", 1) == 0)
		{
			if (ft_strncmp((*list)->content, "##", 2) == 0)
			{
				if (ft_command(env, list) == -1)
					return (0);
			}
			(*list)->content_size = 1;
		}
		else if (ft_part_nb((*list)->content, ' ') == 1)
		{
			if (ft_room_link(env, (*list)->content, cpy_list, *list) == -1)
				return (0);
			(*list)->content_size = 1;
		}
		else
			return (0);
		*list = (*list)->next;
	}
	return (0);
}
