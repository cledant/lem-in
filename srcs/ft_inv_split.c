/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inv_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:19:08 by cledant           #+#    #+#             */
/*   Updated: 2016/06/06 09:30:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*ft_inv_split(char *part_1, char *part_2)
{
	size_t	size;
	char	*new;

	if (*part_1 == '\0' || *part_2 == '\0')
		return (NULL);
	size = ft_strlen(part_1) + ft_strlen(part_2) + 1;
	if ((new = ft_strnew(size)) == NULL)
		return (NULL);
	new = ft_strcat(new, part_2);
	new = ft_strcat(new, "-");
	new = ft_strcat(new, part_1);
	return (new);
}
