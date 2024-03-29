/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:41:46 by cledant           #+#    #+#             */
/*   Updated: 2016/06/24 18:00:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define H_SIZE 2048
# define G_SIZE 1024
# define SEEK_SIZE 10000

typedef struct		s_graph
{
	char			*name;
	char			*hist;
	int				x_coord;
	int				y_coord;
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
	int				ants;
	char			*path;
}					t_env;

void				ft_parser(t_env *env, t_list *list);
void				ft_error(t_env *env, t_list *list);
int					ft_ant_number(t_env *env, t_list **list);
int					ft_room_list(t_env *env, t_list **list);
int					ft_room_connect(t_env *env, t_list **list,
						t_list *cpy_list);
int					ft_room_link(t_env *env, char *link, t_list *cpy_list,
						t_list *cur_lst);
int					ft_create_new_room(t_env *env, char *room);
int					ft_command(t_env *env, t_list **list);
char				*ft_inv_split(char *part_1, char *part_2);
int					ft_has_same(char *norm, char *inv, t_list *begin,
						t_list *curr);
int					ft_create_link(t_env *env, char *from, char *to);
t_graph				*ft_seek_node(t_head *head, char *name);
int					ft_check_room_parsing(t_env *env);
size_t				ft_part_nb(char const *s, char c);
t_env				*ft_env_new(void);
void				ft_env_del(t_env **env);
t_head				*ft_head_new(size_t size);
void				ft_head_del(t_head **head);
int					ft_head_realloc(t_head *head);
t_graph				*ft_graph_new(size_t size);
void				ft_graph_del(t_graph **graph);
int					ft_graph_realloc(t_graph *graph);
t_graph				*ft_graph_seek_name(t_head *head, char *name);
void				ft_graph_seek_end(t_head *old, t_head *new, t_env *env);
void				ft_solver(t_env *env);
void				ft_disp_path(t_env *env);
char				*ft_strjoin_cat(const char *s1, const char *s2, char c);
void				ft_debug_room(t_env *env);
void				ft_debug_link(t_env *env);
void				ft_read_inputs(t_list *list);
void				ft_init_lst(t_list *lst);
t_list				*ft_lstread_prompt(int fd);

#endif
