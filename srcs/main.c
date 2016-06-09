/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:11:17 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 16:31:59 by cledant          ###   ########.fr       */
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

void		ft_debug_room(t_env *env)
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
	{
		ft_putstr("START : ");
		ft_putendl(env->start);
	}
	if (env->end != NULL)
	{
		ft_putstr("END : ");
		ft_putendl(env->end);
	}
}

void		ft_debug_link(t_env *env)
{
	size_t	i;
	size_t	j;
	t_head	*cpy;

	cpy = env->head;
	i = 0;
	j = 0;
	while (i < cpy->curr)
	{
		ft_putendl(cpy->list[i]->name);
		while (j < cpy->list[i]->curr)
		{
			ft_putstr("LINK TO : ");
			ft_putendl(cpy->list[i]->next[j]->name);
			j++;
		}
		j = 0;
		i++;
	}
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
//	ft_putendl("PARSING DONE");
//	ft_putendl("SOLVER");
	ft_solver(env);
//	ft_putendl("DONE SOLVER");
//	if (env->path != NULL)
//		ft_putendl(env->path);
//	else
	if (env->path == NULL)
	{
//		ft_putendl("NO SOLUTION FOUND");
		ft_env_del(&env);
		ft_lstdel(&file, ft_lstfree_malloc);
		return (0);
	}
//	ft_putendl("DISPLAY SOLUTION");
	ft_disp_path(env);
//	ft_putendl("END DISPLAY SOLUTION");
	ft_env_del(&env);
	ft_lstdel(&file, ft_lstfree_malloc);
	return (0);
}
