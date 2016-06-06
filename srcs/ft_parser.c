/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:18:33 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 13:10:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_parser(t_env *env, t_list *list)
{
	t_list	*cpy_list;

	cpy_list = list;
	if (ft_ant_number(env, &cpy_list) == -1)
		ft_error(env, list);
	ft_putendl("ANT NUMBER");
	ft_putnbrendl(env->ants);
	ft_putendl("FIN ANT NUMBER");
	if (env->ants == 0)
		ft_error(env, list);
	if (ft_room_list(env, &cpy_list) == -1)
		ft_error(env, list);
	ft_putendl("DEBUG ROOM");
	ft_debug_room(env);
	ft_putendl("FIN DEBUG ROOM");
	if (ft_check_room_parsing(env) == -1)
	{
		ft_putendl("CHECK NEGATIF");
		ft_error(env, list);
	}
	if (ft_room_connect(env, &cpy_list, cpy_list) == -1)
		ft_error(env, list);
	ft_putendl("DEBUG LINK");
	ft_debug_link(env);
	ft_putendl("FIN DEBUG LINK");
}
