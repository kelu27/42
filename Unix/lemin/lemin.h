/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 16:43:44 by lcharpen          #+#    #+#             */
/*   Updated: 2014/03/23 22:36:03 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "./libft/includes/libft.h"

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

typedef struct		s_path
{
	char			*tube;
	int				count;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_room
{
	char			*room;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct	s_imput
{
		char	*start;
		char	*end;
		t_path	*pathlink;
		t_path	*lastpath;
		t_room	*room;
		int		ant;
		char	**path;
		char	**ants_names;
		int		count;
		char	*temp;
		char	*temp2;
		char	**tab;
		char	**print;
}				t_imput;

void			ft_check(t_imput *data, t_map *map);
void			ft_check_room(t_imput *data, t_map *map);
int				ft_check_diez(char *line);
t_map			*ft_create_elem(char *line);
t_map			*ft_list_push_back(t_map **begin_list, char *line);
t_path			**ft_create_double_circular(void);
void			ft_push_back_doub_cir(t_path **element, char *tube);
t_room			**ft_create_double_circular2(void);
void			ft_push_back_doub_cir2(t_room **element, char *room);
void			ft_error(void);
void			ft_find_path(t_imput *data);
void			ft_lstaddtail(t_path **list, char *content, char *start);
void			ft_print_ant_hill(t_imput *data);
void			ft_save_path(char *tube, t_imput *data);
int				ft_path_exist(char *check, t_imput *data);
void			ft_del_path(t_imput *data);

#endif /*	!LEMIN_H */
