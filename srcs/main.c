/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 12:11:17 by cledant           #+#    #+#             */
/*   Updated: 2016/06/14 13:43:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			main_2(t_env **env, t_list **file)
{
	if ((*env)->debug == 1)
		ft_putendl("DONE SOLVER");
	if ((*env)->path != NULL && (*env)->debug == 1)
		ft_putendl((*env)->path);
	if ((*env)->path == NULL)
	{
		if ((*env)->debug == 1)
			ft_putendl("NO SOLUTION FOUND");
		ft_env_del(env);
		ft_lstdel(file, ft_lstfree_malloc);
		return ;
	}
	if ((*env)->debug == 1)
		ft_putendl("DISPLAY SOLUTION");
	ft_disp_path(*env);
	if ((*env)->debug == 1)
		ft_putendl("END DISPLAY SOLUTION");
	ft_env_del(env);
	ft_lstdel(file, ft_lstfree_malloc);
}

int				main(int argc, char **argv)
{
	t_list	*file;
	t_env	*env;

	file = NULL;
	if ((env = ft_env_new()) == NULL)
		ft_error(env, file);
	if (argc == 2 && ft_strcmp(argv[1], "-v") != 0)
		ft_error(env, file);
	else if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		env->debug = 1;
	else if (argc > 1)
		ft_error(env, file);
	if ((file = ft_lstread_file(0)) == NULL)
		ft_error(env, file);
	if (env->debug == 1)
		ft_putendl("PARSING");
	ft_parser(env, file);
	if (env->debug == 1)
		ft_putendl("PARSING DONE");
	if (env->debug == 1)
		ft_putendl("SOLVER");
	ft_solver(env);
	main_2(&env, &file);
	return (0);
}
