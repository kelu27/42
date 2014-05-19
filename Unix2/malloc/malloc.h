/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 10:26:53 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/20 12:41:36 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <unistd.h>
# define N 128
# define M 1024
# define PAGE getpagesize()

typedef struct		s_block
{
	struct s_block	*next;
	size_t			size;
}					t_block;

typedef struct		s_page
{
	void			*page;
	void			*start;
	int				type;
	int				nb_elem;
}					t_page;

typedef struct		s_type
{
	t_page			tiny;
	t_page			small;
	t_page			large;
}					t_type;

struct s_type		m_type;
void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				new_block(size_t size);
void				*new_tiny_header(size_t size);
void				*new_small_header(size_t size);
void				*new_large_header(size_t size);
void				ft_putstr(char const *s);

#endif
