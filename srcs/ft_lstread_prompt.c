/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstread_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 17:59:25 by cledant           #+#    #+#             */
/*   Updated: 2016/06/24 18:00:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read_routine(int ret, t_list *list, char **line)
{
	t_list	*new;

	if (ret == -1)
	{
		if (list != NULL)
			ft_lstdel(&list, &ft_bzero);
		return (0);
	}
	if (ret == 1 || (ret == 0 && **line != '\0'))
	{
		if ((new = ft_lstnew(*line, ft_strlen(*line) + 1)) == NULL)
		{
			ft_lstdel(&list, &ft_lstfree_malloc);
			if (*line != NULL)
				ft_strdel(line);
			return (0);
		}
		if (*line != NULL)
			ft_strdel(line);
		ft_lstpushback(list, new);
	}
	return (1);
}

t_list			*ft_lstread_prompt(int fd)
{
	t_list	*list;
	char	*line;
	int		ret;

	if (fd < 0)
		return (NULL);
	ret = gnl_prompt(fd, &line);
	if (ret == -1)
		return (NULL);
	if ((list = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
	{
		if (line != NULL)
			ft_strdel(&line);
		return (NULL);
	}
	if (line != NULL)
		ft_strdel(&line);
	while ((ret = gnl_prompt(fd, &line)) == 1)
		if (ft_read_routine(ret, list, &line) == 0)
			return (NULL);
	if (ft_read_routine(ret, list, &line) == 0)
		return (NULL);
	if (line != NULL)
		ft_strdel(&line);
	return (list);
}
