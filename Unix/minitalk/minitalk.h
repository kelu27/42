/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:41:23 by ppellegr          #+#    #+#             */
/*   Updated: 2014/02/07 21:41:24 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUF 1024

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				ft_power(int i);
char			*ft_realloc(char *s, int size);

#endif /* !MINITALK_H */
