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
	size_t		size;
	size_t		i;
	size_t		j;
	size_t		first;

	i = 1;
	j = 0;
	first = 1;
	size = ft_part_nb(env->path, ' ');
	if ((split = ft_strsplit(env->path, ' ')) == NULL)
		return ;
	while (first < env->ants)
	{
		j = first;
		while (i < size)
		{
			//if (j - i > 0 && j <= env->ants)
			{
				ft_putchar('L');
				ft_putnbr(j);
				ft_putchar('-');
				ft_putstr(split[i]);
			}
			i++;
			if (i == size)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			j++;
		}
		j = 1;
		i = 1;
		first++;
	}
	ft_strdel_char2(&split);
}
