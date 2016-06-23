/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 18:18:33 by cledant           #+#    #+#             */
/*   Updated: 2016/06/23 23:32:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_parser(t_env *env, t_list *list)
{
	t_list	*cpy_list;

	cpy_list = list;
	if (ft_ant_number(env, &cpy_list) == -1)
		ft_error(env, list);
	if (env->ants <= 0)
		ft_error(env, list);
	if (ft_room_list(env, &cpy_list) == -1)
		ft_error(env, list);
	if (env->start == NULL || env->end == NULL)
		ft_error(env, list);
	if (ft_check_room_parsing(env) == -1)
		ft_error(env, list);
	ft_room_connect(env, &cpy_list, cpy_list);
}
