/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:39:56 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 17:02:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_env_del(t_env **env)
{
	if ((*env)->head != NULL)
		ft_head_del(&((*env)->head));
	if ((*env)->start != NULL)
		ft_strdel(&((*env)->start));
	if ((*env)->end != NULL)
		ft_strdel(&((*env)->end));
	free(*env);
	*env = NULL;
}
