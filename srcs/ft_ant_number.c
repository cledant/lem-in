/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:28:38 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 18:37:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_ant_number(t_env *env, t_list **list)
{
	while (*list != NULL)
	{
		if (ft_strncmp((*list)->content, "#", 1) == 0)
		{
			if (ft_strncmp((*list)->content, "##", 2) == 0)
			{
				if (ft_command(env, list) == -1)
					return (-1);
			}
		}
		else if (ft_part_nb((*list)->content, ' ') == 1)
		{
			env->ants = ft_atoi((*list)->content);
			*list = (*list)->next;
			return (0);
		}
		else
			return (-1);
		*list = (*list)->next;
	}
	return (-1);
}
