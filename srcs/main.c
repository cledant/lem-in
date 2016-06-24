/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:11:17 by cledant           #+#    #+#             */
/*   Updated: 2016/06/24 18:00:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(int argc, char **argv)
{
	t_list	*file;
	t_env	*env;

	file = NULL;
	argv[0] = "a";
	if ((env = ft_env_new()) == NULL)
		ft_error(env, file);
	if (argc > 1)
		ft_error(env, file);
	if ((file = ft_lstread_prompt(0)) == NULL)
		ft_error(env, file);
	ft_init_lst(file);
	ft_parser(env, file);
	ft_solver(env);
	if (env->path == NULL)
		ft_error(env, file);
	ft_read_inputs(file);
	ft_disp_path(env);
	ft_env_del(&env);
	ft_lstdel(&file, ft_lstfree_malloc);
	return (0);
}
