/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:11:17 by cledant           #+#    #+#             */
/*   Updated: 2016/06/05 13:14:33 by cledant          ###   ########.fr       */
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
	exit (-1);
}

static void		ft_debug_room(t_env *env)
{
	size_t	i;
	t_head	*cpy;

	cpy = env->head;
	i = 0;
	while (i < cpy->curr)
	{
		ft_putstr(cpy->list[i]->name);
		ft_putstr(" ");
		ft_putnbr(cpy->list[i]->x_coord);
		ft_putstr(" ");
		ft_putnbrendl(cpy->list[i]->y_coord);
		i++;
	}
	if (env->start != NULL)
		ft_putendl(env->start);
	if (env->end != NULL)
		ft_putendl(env->end);
}

int				main(void)
{
	t_list	*file;
	t_env	*env;

	file = NULL;
	if ((env = ft_env_new()) == NULL)
		ft_error(env, file);
	if ((file = ft_lstread_file(0)) == NULL)
		ft_error(env, file);
	ft_parser(env, file);
	ft_putendl("PARSING DONE");
	ft_putnbrendl(env->ants);
	ft_debug_room(env);
	ft_env_del(&env);
	ft_lstdel(&file, ft_lstfree_malloc);
	return (0);
}
