/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:26:27 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 19:52:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_env		*ft_env_new(void)
{
	t_env	*new;

	if ((new = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((new->head = ft_head_new(H_SIZE)) == NULL)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->start = NULL;
	new->end = NULL;
	new->ants = 0;
	return (new);
}
