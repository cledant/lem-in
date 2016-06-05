/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:31:28 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 12:52:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_clean(t_graph **new, char ***split)
{
	if (*split != NULL)
		ft_strdel_char2(split);
	if (*new != NULL)
		ft_graph_del(new);
}

static int		ft_add_to_head(t_env *env, t_graph *new)
{
	t_head	*e_head;
	size_t	i;

	i = 0;
	e_head = env->head;
	if (e_head->curr == e_head->max)
		if (ft_head_realloc(e_head) == -1)
			return (-1);
	while (i < e_head->curr)
		i++;
	e_head->list[i] = new;
	return (0);
}

int				ft_create_new_room(t_env *env, char *room)
{
	char		**split;
	t_graph		*new;

	if ((split = ft_strsplit(room, ' ')) == NULL)
		return (-1);
	if ((room == ft_graph_new(G_SIZE)) == NULL)
	{
		ft_clean(&room, &split);
		return (-1);
	}
	if ((new->name = ft_strdup(split[0])) == NULL)
	{	
		ft_clean(&room, &split);
		return (-1);
	}
	x_coord = ft_atoi(split[1]);
	y_coord = ft_atoi(split[2]);
	if (ft_add_to_head(env, new) == -1)
	{
		ft_clean(&room, &split);
		return (-1);
	}
	ft_strdel_char2(split);
	return (0);
}
