/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 20:20:04 by cledant           #+#    #+#             */
/*   Updated: 2016/06/23 13:17:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_read_inputs(t_list *list)
{
	t_list	*cpy_list;

	cpy_list = list;
	if (cpy_list == NULL)
		return ;
	while (cpy_list != NULL && cpy_list->content_size == 1)
	{
		ft_putendl(cpy_list->content);
		cpy_list = cpy_list->next;
	}
	ft_putendl("");
}
