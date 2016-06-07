/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 09:54:51 by cledant           #+#    #+#             */
/*   Updated: 2016/06/07 12:01:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solver(t_env *env)
{
	t_head		*stack_1;
	t_head		*stack_2;

	if ((stack_1 = ft_head_new(SEEK_SIZE)) == NULL)
		return ;
	if ((stack_2 = ft_head_new(SEEK_SIZE)) == NULL)
		return ;
	if ((stack_1->list[0] = ft_graph_seek_name(env->head, env->start)) == NULL)
		return ;
	if ((stack_1->list[0]->hist = ft_strdup(stack_1->list[0]->name)) == NULL)
		return ;
	stack_1->curr++;
	ft_graph_seek_end(stack_1, stack_2, env);
	free(stack_1->list);
	free(stack_2->list);
	free(stack_1);
	free(stack_2);
}
