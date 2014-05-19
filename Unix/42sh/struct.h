/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:44:57 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 18:47:36 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>

typedef	struct			s_data
{
	char				read_char[5];
	char				buffer[200];
	struct termios		m_term;
}						t_data;

typedef struct			s_list
{
	char				value;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef struct			s_history
{
	struct s_list		*cmd;
	struct s_history	*prev;
	struct s_history	*next;
}						t_history;

typedef struct			s_token
{
	char				*name;
	int					type;
	struct s_token		*next;
	struct s_token		*prev;
	int					is_prior;
}						t_token;

typedef struct			s_tree
{
	char				*name;
	int					type;
	int					exec;
	int					fildes[2];
	struct s_tree		*father;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

typedef struct			s_cmd
{
	char				*newcmd;
	int					i;
	int					j;
}						t_cmd;

typedef struct			s_fd
{
	int					fdin;
	int					fdout;
}						t_fd;

#endif