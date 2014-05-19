/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:26:22 by lcharpen          #+#    #+#             */
/*   Updated: 2014/01/11 15:22:09 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <string.h>

# define CONFIG (ft_create_double_circular())

typedef struct				s_list
{
	char					*content;
	int						selected;
	struct s_list			*next;
	struct s_list			*prev;
}							t_list;

typedef struct				s_item
{
	unsigned int			word_lenght;
	unsigned int			word;
	unsigned int			line;
	unsigned int			col;
	unsigned int			x;
}							t_item;

t_list			**ft_create_double_circular(void);
t_list			**ft_create2(void);
t_list			**ft_create3(void);
t_list			*ft_push_back_doub_cir(t_list **element, char *content);
t_item			*ft_item_init(void);
void			ft_putstr(char const *s);
int				tty_putchar(int i);
void			ft_putstr_fd(const char *s);
char			*ft_strcpy(char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			ft_underline(void);
void			ft_delete_content(t_list **cursor, char *buf);
void			ft_cursor_select(t_list **cursor, char *buf);
void			ft_cursor(t_list **cursor, char *buf);
void			ft_keep_entry(t_list **l_a, char *buf);
struct termios	ft_termios_init();
struct termios	*original_term();
void			ft_take_signal(int sign);
void			ft_close_term(struct termios term);
int				ft_word_lenght(t_list *list);

#endif	/* !FT_SELECT_H */
