/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 20:01:30 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 20:03:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char *s, char c, size_t result)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
		else
		{
			result++;
			while (*s != c)
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
	}
	return (result);
}

size_t			ft_part_nb(char const *s, char c)
{
	size_t	words;

	words = 0;
	words = ft_word_count((char *)s, c, words);
	return (words);
}
