/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:46:29 by cledant           #+#    #+#             */
/*   Updated: 2016/06/07 19:03:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_disp_path(t_env *env)
{
	char		**split;
	long int	*tab;
	size_t		i;
	size_t		j;
	size_t		one;
	size_t		size;

	i = 0;
	size = ft_part_nb(env->path, ' ');
	if ((split = ft_strsplit(env->path, ' ')) == NULL)
		return ;
	if ((tab = (long int *)malloc(sizeof(long int) * size)) == NULL)
	{
		ft_clean(split, tab);
		return ;
	}
	while (i < size)
	{
		tab[i][0] = 1 - i;
		tab[i][1] = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		
	}
}
