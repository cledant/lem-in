/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:18:33 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 16:45:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_parser(t_env *env, t_list *list)
{
	t_list	*cpy_list;

	cpy_list = list;
	if (ft_ant_number(env, &cpy_list) == -1)
		ft_error(env, list);
//	ft_putendl("1");
	if (ft_room_list(env, &cpy_list) == -1)
		ft_error(env, list);
//	ft_putendl("2");
//	ft_putendl("DEBUG ROOM");
//	ft_debug_room(env);
//	ft_putendl("FIN DEBUG ROOM");
	if (ft_check_room_parsing(env) == -1)
		ft_error(env, list);
//	ft_putendl("3");
//	if (ft_room_connect(env, cpy_list) == -1)
//		return ;
}
