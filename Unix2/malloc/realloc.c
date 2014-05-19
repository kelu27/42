/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:42:52 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/20 11:42:55 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	free(ptr);
	ptr = malloc(size);
	return (ptr);
}
