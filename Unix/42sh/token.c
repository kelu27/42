/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:45:41 by nschilli          #+#    #+#             */
/*   Updated: 2014/03/26 17:43:49 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

char		*get_cmd_token(char *line, int pb, int pe)
{
	char	*token_name;
	int		i;

	i = 0;
	if (!(token_name = (char *)malloc(sizeof(char) * (pe - pb) + 1)))
		ft_error(1, "get_cmd_token");
	while (pb < pe)
	{
		token_name[i] = line[pb];
		i++;
		pb++;
	}
	token_name[i] = '\0';
	return (token_name);
}

void		ft_lexertoken2(char *line, int i, t_token **token)
{
	if (line[i] == ';')
		ft_pushback_token(token, ft_newtoken(";", 1));
	else if (line[i] == '&' && line[i + 1] == '&')
		ft_pushback_token(token, ft_newtoken("&&", 2));
	else if (line[i] == '|' && line[i + 1] == '|')
		ft_pushback_token(token, ft_newtoken("||", 2));
	else if (line[i] == '|' && line[i + 1] != '|')
		ft_pushback_token(token, ft_newtoken("|", 3));
	else if (line[i] == '>' && line[i + 1] != '>')
		ft_pushback_token(token, ft_newtoken(">", 4));
	else if (line[i] == '<' && line[i + 1] != '<')
		ft_pushback_token(token, ft_newtoken("<", 4));
	else if (line[i] == '>' && line[i + 1] == '>')
		ft_pushback_token(token, ft_newtoken(">>", 4));
	else if (line[i] == '<' && line[i + 1] == '<')
		ft_pushback_token(token, ft_newtoken("<<", 4));
}

int			get_pe(char *line, int i)
{
	while (line[i] != '\0' && (ft_isalphanum(line[i]) != 0 || line[i] == '\"'
				|| line[i] == '\''))
	{
		i++;
		while ((line[i] == ' ' || line[i] == '\t' || line[i] == '.'
			|| line[i] == '/') && line[i] != '\0')
		{
			i++;
			if (line[i] == '-')
			{
				i++;
				break ;
			}
		}
	}
	return (i);
}

t_token		*ft_lexertoken(char *line)
{
	int		i;
	int		pb;
	int		pe;
	t_token	*token;

	i = 0;
	pb = 0;
	pe = 0;
	token = NULL;
	while (line[i] != '\0')
	{
		i = get_pe(line, i);
		pe = i;
		ft_pushback_token(&token, ft_newtoken(get_cmd_token(line, pb, pe), 5));
		ft_lexertoken2(line, i, &token);
		while (ft_isalphanum(line[i]) == 0 && line[i] != '\"' && line[i] != '\''
				&& line[i] != '\0')
			i++;
		pb = i;
		if (line[i] == '\0')
			break ;
	}
	return (token);
}
