/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 12:07:12 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/29 20:10:41 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int					main(int argc, char **argv);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
t_list				*ft_create_elem(int content);
t_list				*ft_list_push_back(t_list **begin_list, int content);
t_list				*ft_list_push_front(t_list **begin_list, int content);
int					ft_check_content(t_list *l_a, t_list *l_b);
void				ft_swap_s(t_list **l_a, t_list **l_b, char op_name);
void				ft_swap_sa(t_list **l_a);
void				ft_swap_sb(t_list **l_b);
void				ft_swap_ss(t_list **l_a, t_list **l_b);
void				ft_take_p(t_list **l_a, t_list **l_b, char op_name);
void				ft_take_pa(t_list **l_a, t_list **l_b);
void				ft_take_pb(t_list **l_a, t_list **l_b);
void				ft_rotate_r(t_list **l_a, t_list **l_b, char op_name);
void				ft_rotate_ra(t_list **l_a);
void				ft_rotate_rb(t_list **l_b);
void				ft_rotate_rab(t_list **l_a, t_list **l_b);
void				ft_rotate_rr(t_list **l_a, t_list **l_b, char op_name);
void				ft_rotate_rra(t_list **l_a);
void				ft_rotate_rrb(t_list **l_b);
void				ft_rotate_rrr(t_list **l_a, t_list **l_b);
int					ft_last_content(t_list *test);
int					ft_algo_sort(t_list **l_a, t_list **l_b, int j);

#endif	/* !FT_PUSH_SWAP_H */
