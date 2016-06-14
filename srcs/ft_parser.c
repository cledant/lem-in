/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:18:33 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 12:45:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_show_debug(t_env *env, size_t mode)
{
	if (mode == 1)
	{
		ft_putendl("ANT NUMBER");
		ft_putnbrendl(env->ants);
		ft_putendl("FIN ANT NUMBER");
	}
	else if (mode == 2)
	{
		ft_putendl("DEBUG ROOM");
		ft_debug_room(env);
		ft_putendl("FIN DEBUG ROOM");
	}
	else if (mode == 3)
	{
		ft_putendl("DEBUG LINK");
		ft_debug_link(env);
		ft_putendl("FIN DEBUG LINK");
	}
}

void			ft_parser(t_env *env, t_list *list)
{
	t_list	*cpy_list;

	cpy_list = list;
	if (ft_ant_number(env, &cpy_list) == -1)
		ft_error(env, list);
	if (env->debug == 1)
		ft_show_debug(env, 1);
	if (env->ants == 0)
		ft_error(env, list);
	if (ft_room_list(env, &cpy_list) == -1)
		ft_error(env, list);
	if (env->debug == 1)
		ft_show_debug(env, 2);
	if (ft_check_room_parsing(env) == -1)
	{
		if (env->debug == 1)
			ft_putendl("CHECK NEGATIF");
		ft_error(env, list);
	}
	ft_room_connect(env, &cpy_list, cpy_list);
	if (env->debug == 1)
		ft_show_debug(env, 3);
}
