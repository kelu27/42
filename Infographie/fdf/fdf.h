/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 14:48:48 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/21 18:52:32 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/includes/libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**tab;
	int			numline;
	int			color;
}				t_env;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_line
{
	int			d;
	int			dx;
	int			dy;
	int			aincr;
	int			bincr;
	int			xincr;
	int			yincr;
	int			x;
	int			y;
}				t_line;

int				ft_count_line(char *argv);
int				ft_str_strlen(char **str);
int				*ft_convert(char *line);
void			fill_in_tab(char *argv, t_env *e);
int				ft_count_line(char *argv);
void			draw(t_env *e);
void			draw_square(t_env *e);
void			ft_line(t_coord *p, int x2, int y2, t_env *e);
t_coord			*init_coord(int x, int y, int z);
int				calcx(int x, int y);
int				calcy(int x, int y, int z);

#endif
