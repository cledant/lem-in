/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:41:46 by cledant           #+#    #+#             */
/*   Updated: 2016/06/04 19:59:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define H_SIZE 1024
# define G_LIST 16

typedef struct		s_graph
{
	char			*name;
	size_t			x_coord;
	size_t			y_coord;
	size_t			max;
	size_t			curr;
	struct s_graph	**next;
}					t_graph;

typedef struct		s_head
{
	size_t			curr;
	size_t			max;
	t_graph			**list;
}					t_head;

typedef struct		s_env
{
	t_head			*head;
	char			*start;
	char			*end;
	size_t			ants;
}					t_env;

void				ft_parser(t_env *env, t_list *list);
int					ft_ant_number(t_env *env, t_list *list);
size_t				ft_part_nb(char const *s, char c);
t_env				*ft_env_new(void);
void				ft_env_del(t_env **env);
t_head				*ft_head_new(size_t size);
void				ft_head_del(t_head **head);
void				ft_head_realloc(t_head **head, size_t size);
t_graph				*ft_graph_new(size_t size);
void				ft_graph_del(t_graph **graph);
void				ft_graph_realloc(t_graph **graph, size_t size);

#endif
