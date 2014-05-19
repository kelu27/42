/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgil <jgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 11:57:36 by jgil              #+#    #+#             */
/*   Updated: 2014/03/27 20:28:45 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define BUFF_SIZE 256
# define RD *(unsigned int *)data.read_char
# define TERMIOS struct termios
# include <string.h>
# include "struct.h"

/*
** board_reader.c
*/
void		board_reader(t_history **hist, t_list **cursor,
	t_list **cmd, char read_char[5]);

/*
** reader_two.c
*/
t_data		reset_readchar(t_data data);
void		delete_cursor(t_list **cursor, t_list **cmd, char read_char[5]);
void		display_char(t_list **cursor, t_list **cmd, char read_char[5]);
void		display_prompt(t_list **cursor, t_list **cmd);
int			save_line(char **line, t_history **hist, t_list **cmd);

/*
** reader.c
*/
void		board_cursor(t_list *cmd, t_list *cursor);
void		moove_cursor(t_list **cursor, char read_char[5]);
void		history_two(t_history **hist, t_list **cursor, t_list **cmd);
void		history(t_history **hist, t_list **cursor, t_list **cmd);
int			reader(char **line, t_data data);

/*
** ft_operator_two.c
*/
void		ft_operator_two(char ***env, t_tree *tree);

/*
** ft_operator.c
*/
t_tree		*ft_board_operator(char ***env, t_tree *tree);

/*
** parser.c
*/
t_token		*ft_find_priority(t_token *token, t_token *stop, t_tree **tree);
t_tree		*ft_parser(t_token *token);

/*
** tree.c
*/
void		prefix(t_tree *tree);
void		infix(char ***env, t_tree *tree, int i);
t_tree		*new_node(t_tree *tree, t_tree *father, char *name, int type);
void		tree_right(t_tree **tree, char *name, int type);
void		tree_left(t_tree **tree, char *name, int type);

/*
** tokenlist.c
*/
t_token		*ft_newtoken(char *name, int type);
void		ft_pushback_token(t_token **list_token, t_token *newtoken);

/*
** token.c
*/
char		*get_cmd_token(char *line, int pb, int pe);
void		ft_lexertoken2(char *line, int i, t_token **token);
t_token		*ft_lexertoken(char *line);

/*
** auxiliary functions
*/
int			strstrlen(char **tab);
int			ft_strlen(char *str);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strdup(char *s1);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strnew(size_t size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		**tabsub(char **tab, unsigned int start, size_t len);
char		**ft_strsplit(char const *s, char c);
char		*ft_strtrim(char *s);
void		ft_echo_scan(char **av, int i, t_fd *fd);
int			ft_echo(char **av, t_fd *fd);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strequ_nocase(char const *s1, char const *s2);
int			ft_isprint(int c);
void		ft_putnbr(int n);
int			ft_isalpha(int c);
int			ft_isalphanum(int c);
void		ft_putchar(char c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strjoin_char(char *s1, char c);
char		*join_free(char *s1, char *s2);
int			ft_atoi(const char *str);

/*
** display functions
*/
void		ft_putstr(char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl(char *str);
void		ft_putendl_fd(char *str, int fd);
void		ft_putstr_echo_fd(char *str, int fd, char c);

/*
** project core
*/
int			is_it_builtins(char ***env, char **av, t_fd *fd);
int			ft_env(char **env, char **arg, t_fd *fd);
int			print_env(char **env, t_fd *fd);
int			ft_cd(char ***env, char **av);
int			get_env(char **environ, char ***env);
int			ft_setenv(char ***env, char *name, char *value, int overwrite);
int			exec_setenv(char ***env, char **av, t_fd *fd);
int			ft_unsetenv(char ***env, char *name, int size);
int			exec_unsetenv(char ***env, char **av);
void		exec_pipe(char ***env, t_tree *tree, t_fd *fd);
int			find_char(char *str, char x);
char		*change_into(char a, char b, char *line);
int			do_the_cmd(char ***env, char **av, t_fd *fd);
char		*get_in_env(char **env, char *target);
char		*save_path(char **env, int n);
char		*ft_prompt(void);
int			find_operator(t_token *list);
t_tree		*create_tree(t_token *list, t_tree *node);
t_token		*find_priority(t_token *list);
t_token		*get_left_op(t_token *list);
t_fd		*ft_init_fd(void);
void		echo_option(char *first, char *av, t_fd *fd);
void		ft_error(int n, char *where);
char		*new_line(char *str, t_list *line);
t_tree		*ft_operator_four(char ***e, t_tree *tree);

/*
** termcaps functions
*/
t_data		init_data();
t_list		*backspace_char(t_list **cursor);
t_list		*delete_char(t_list	**cursor);
int			tputs_putchar(int c);
void		board_cursor(t_list *cmd, t_list *cursor);
int			reader(char **line, t_data data);
int			tputs_putchar(int c);
void		term_close(struct termios *term);
TERMIOS		*ft_init_term(void);
void		init_shell(struct termios *m_term);
void		term_close(struct termios *term);
void		init_list(t_list **list);
t_list		*insert_char(t_list **cursor, char value);
char		*lst_to_str(t_list *list);
void		replace_cursor(t_list	*cursor);
t_history	*add_in_history(t_history *hist, t_list *cmd);
void		replace_cursor_left(t_list *cursor);
int			save_line_checker(t_list *list);
t_list		*cpy_lst(t_list	*hist);
void		replace_cursor_right(t_list *cursor);

#endif
