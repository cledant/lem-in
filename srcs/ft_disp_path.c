/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:46:29 by cledant           #+#    #+#             */
/*   Updated: 2016/06/09 22:15:27 by cledant          ###   ########.fr       */
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

static void		ft_show_val(size_t *tab, size_t (*val)[5], char **split,
					size_t size)
{
	if ((*val)[1] != size - 1 && (*val)[0] != 0)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(tab[(*val)[1]]);
	ft_putchar('-');
	ft_putstr(split[(*val)[1]]);
	(*val)[0]++;
}

static int		ft_val_init(size_t (*val)[5], size_t **tab, char ***split,
					t_env *env)
{
	(*val)[2] = 0;
	(*val)[0] = 1;
	(*val)[4] = ft_part_nb(env->path, ' ');
	(*val)[1] = (*val)[4] - 1;
	if ((*split = ft_strsplit(env->path, ' ')) == NULL)
		return (-1);
	if ((*tab = (size_t *)malloc(sizeof(size_t) * (*val)[4])) == NULL)
	{
		ft_strdel_char2(split);
		return (-1);
	}
	ft_bzero(*tab, sizeof(size_t) * (*val)[4]);
	return (0);
}

void			ft_disp_path(t_env *env)
{
	char		**split;
	size_t		val[5];
	size_t		*tab;

	if (ft_val_init(&val, &tab, &split, env) == -1)
		return ;
	while (val[0] > 0)
	{
		ft_roll_value(tab, val[4], &val[2]);
		val[0] = 0;
		while (val[1] > 0)
		{
			if (tab[val[1]] > 0 && tab[val[1]] <= env->ants)
				ft_show_val(tab, &val, split, val[4]);
			val[1]--;
			if (val[0] != 0 && val[1] == 0)
				ft_putchar('\n');
		}
		val[1] = val[4] - 1;
	}
	free(tab);
	ft_strdel_char2(&split);
}
