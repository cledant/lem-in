/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:34:02 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 18:57:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static inline int		ft_known_command(char *command)
{
	if (strcmp(command, "##start") == 0)
		return (1);
	else if (strcmp(command, "##end") == 0)
		return (1);
	else
		return (0);
}

static inline int		ft_add_command(t_env *env, t_list **list,
							char **cpy_in)
{
	char	**split;

	while (1)
	{
		if ((*list = (*list)->next) == NULL)
			return (-1);
		if (ft_strncmp((*list)->content, "##", 2) == 0)
		{
			if (ft_known_command((*list)->content) == 1)
				return (-1);
		}
		else if (ft_strncmp((*list)->content, "#", 1) != 0 &&
					ft_part_nb((*list)->content, ' ') == 3)
			break ;
	}
	if (ft_part_nb((*list)->content, ' ') != 3)
		return (-1);
	if ((split = ft_strsplit((*list)->content, ' ')) == NULL)
		return (-1);
	if ((*cpy_in = ft_strdup(split[0])) == NULL)
	{
		ft_strdel_char2(&split);
		return (-1);
	}
	ft_strdel_char2(&split);
	if (ft_create_new_room(env, (*list)->content) == -1)
		return (-1);
	return (0);
}

int						ft_command(t_env *env, t_list **list)
{
	if (ft_strcmp((*list)->content, "##start") == 0)
	{
		if (env->start != NULL)
			return (-1);
		if (ft_add_command(env, list, &env->start) == -1)
			return (-1);
	}
	else if (ft_strcmp((*list)->content, "##end") == 0)
	{
		if (env->end != NULL)
			return (-1);
		if (ft_add_command(env, list, &env->end) == -1)
			return (-1);
	}
	return (0);
}
