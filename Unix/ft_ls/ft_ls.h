/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:48:33 by lcharpen          #+#    #+#             */
/*   Updated: 2013/12/13 20:57:54 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>

int		ft_list_dir(void);
int		ft_list_dir_a(void);
//void	ft_newchain(t_args **file, char *filename);

typedef struct	s_args
{
char			*arg;
char			*file;
struct s_args	*next;
struct s_args	*prev;
}				t_args;


#endif	/* !FT_LS_H */
