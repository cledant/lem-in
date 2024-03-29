/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:40:55 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 20:01:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_error(t_env *env, t_list *list)
{
	if (env != NULL)
		ft_env_del(&env);
	if (list != NULL)
	{
		ft_read_inputs(list);
		ft_lstdel(&list, ft_lstfree_malloc);
	}
	ft_putendl("ERROR");
	exit(-1);
}
