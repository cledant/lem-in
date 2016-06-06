/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 19:54:24 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 11:14:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_clean(char ***split, char **inv)
{
	if (*split != NULL)
		ft_strdel_char2(split);
	if (*inv != NULL)
		ft_strdel(inv);
}

int				ft_room_link(t_env *env, char *link, t_list *cpy_list,
					t_list *cur_lst)
{
	char	**split;
	char	*inv;

	if (ft_part_nb(link, ' ') != 2)
		return (-1);
	if ((split = ft_strsplit(link, '-')) == NULL)
		return (-1);
	if ((inv = ft_inv_split(split[0], split[1])) == NULL)
	{
		ft_clean(&split, &inv);
		return (-1);
	}
	if (ft_has_same(link, inv, cpy_list, cur_lst) == 1)
	{
		ft_clean(&split, &inv);
		return (-1);
	}
	if (ft_create_link(env, split[0], split[1]) == -1)
	{
		ft_clean(&split, &inv);
		return (-1);
	}
	ft_clean(&split, &inv);
	return (0);
}
