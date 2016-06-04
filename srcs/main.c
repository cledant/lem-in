/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:11:17 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 18:30:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_error(t_env *env, t_list *list)
{
	if (env != NULL)
		ft_env_del(&env);
	if (list != NULL)
		ft_lstdel(&list, ft_lstfree_malloc);
	ft_putendl_fd("ERROR", 2);
	exit (-1);
}

int				main(void)
{
	t_list	*file;
	t_env	*env;

	file = NULL;
	if ((env = ft_env_new()) == NULL)
		ft_error(env, list);
	if ((file = ft_lstread_file(0)) == NULL)
		ft_error(env, list);
	ft_parser(env, list);
	ft_putendl("PARSING DONE");
	ft_env_del(&env);
	ft_lstdel(&list, ft_lstfree_malloc);
	return (0);
}
