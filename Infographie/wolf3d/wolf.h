/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:50:01 by lcharpen          #+#    #+#             */
/*   Updated: 2014/05/14 11:53:04 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <X11/xlib.h>
# include "./libft/includes/libft.h"

# define LENGTH 1900
# define HEIGHT 1080

typedef struct			s_vec
{
	int					x;
	int					y;
}						t_vec;

typedef struct			s_event_list
{
	int					mask;
	int					(*hook)();
	void				*param;
}						t_event_list;

typedef struct			s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[LASTEvent];
}						t_win_list;

typedef struct			s_xvar
{
	Display				*display;
	Window				root;
	int					screen;
	int					depth;
	Visual				*visual;
	Colormap			cmap;
	int					private_cmap;
	t_win_list			*win_list;
	int					(*loop_hook)();
	void				*loop_param;
	int					use_xshm;
	int					pshm_format;
	int					do_flush;
	int					decrgb[6];
}						t_xvar;

typedef struct			s_env
{
	t_xvar				*mlx;
	char				*keys;
	void				*win;
	void				*img_mlx;
	void				*img_win;
	int					fd;
	int					bitpp;
	int					size_l;
	int					endian;
	float				walltype;
	float				walltype2;
	char				*data;
	float				x;
	float				y;
	float				dst;
	float				angle;
	int					side;
	int					**tab;
	int					numline;
	t_vec				wall;
	XImage				*image;
	Pixmap				pix;
	GC					gc;
}						t_env;

void					print_wall(t_env *e, int x);
float					dst_calcul(t_env *img, float x1, float y1);
void					move_able(t_env *e, float x, float y);
void					wall_down(t_env *e, int y, int h);
void					sky(t_env *img);
void					wall(t_env *img);
void					floori(t_env *img);
int						mlx_pxl_put_to_img(t_env *img, int x, int y, int color);
void					key_hook(t_env *e);
int						expose_hook(t_env *e);
int						ft_wolf(t_env *e);
int						ft_count_line(char *argv);
int						ft_str_strlen(char **str);
int						*ft_convert(char *line);
void					fill_in_tab(char *argv, t_env *e);
int						ft_count_line(char *argv);
int						loop_hook(t_env *e);

#endif
