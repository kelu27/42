/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballu <vballu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:34:50 by vballu            #+#    #+#             */
/*   Updated: 2014/03/08 21:48:18 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ALCU_H
# define ALCU_H

# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef enum	e_bool
{
	false = 0,
	true
}				t_bool;

typedef struct	s_map
{
	int		tall;
	int		wide;
	char	**stage;
}				t_map;

t_bool		ft_badarg(void);

t_map		*map_singleton(void);
void		ft_create_map(char *line, char *col);


void		ft_print_map(void);

void		ft_bpoint(void *s, size_t n);
int			ft_putoken(char *maxline, char *maxcol, char *numcol);
int			ft_putoken2(char *maxline, char *maxcol, char *numcol);
int			ft_check(int maxline, int maxcol, int line, int col);

#endif	/* !ALCU_H */
