/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:46:29 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 16:31:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_roll_value(size_t *tab, size_t size, size_t *j)
{
	size_t		i;
	size_t		tab_2[size];

	(*j)++;
	i = 0;
	while (i < size)
	{
		if (i + 1 == size)
			tab_2[0] = tab[size - 1];
		else
			tab_2[i + 1] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = tab_2[i];
		i++;
	}
	tab[1] = *j;
}

void			ft_disp_path(t_env *env)
{
	char		**split;
	size_t		size;
	size_t		*tab;
	size_t		disp;
	size_t		old_disp;
	size_t		i;
	size_t		j;
//	size_t		test;

	j = 0;
	disp = 1;
//	test = 0;
	size = ft_part_nb(env->path, ' ');
	i = size - 1;
	if ((split = ft_strsplit(env->path, ' ')) == NULL)
		return ;
	if ((tab = (size_t *)malloc(sizeof(size_t) * size)) == NULL)
		return ;
	ft_bzero(tab, sizeof(size_t) * size);
	while (disp > 0)
	{
		ft_roll_value(tab, size, &j);
//		while (test < size)
//		{
//			ft_putnbrendl(tab[test]);
//			test++;
//		}
//		test = 0;
		disp = 0;
		while (i > 0)
		{
			old_disp = disp;
			if (tab[i] > 0 && tab[i] <= env->ants)
			{
				if (i != size - 1 && disp != 0)
					ft_putchar (' ');
				ft_putchar('L');
				ft_putnbr(tab[i]);
				ft_putchar('-');
				ft_putstr(split[i]);
				disp++;
			}
			i--;
			if (disp != 0 && i == 0)
				ft_putchar ('\n');
		}
		i = size - 1;
	}
	free(tab);
	ft_strdel_char2(&split);
}
