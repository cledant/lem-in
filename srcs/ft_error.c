/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:40:55 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 12:41:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_error(t_env *env, t_list *list)
{
	if (env != NULL)
		ft_env_del(&env);
	if (list != NULL)
		ft_lstdel(&list, ft_lstfree_malloc);
	ft_putendl_fd("ERROR", 2);
	exit(-1);
}
