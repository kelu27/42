/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 20:20:48 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/20 13:30:29 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

void free (void *ptr)
{
	size_t	len;
	size_t	blocklen;
	t_block	*block;

	blocklen = sizeof(block->size) + sizeof(block->next);
	ptr -= blocklen;
	if (*(size_t *)ptr > 1024)
	{
		len = *(size_t *)ptr + blocklen;
		munmap(ptr, (len / PAGE + (len % PAGE != 0)) * PAGE);
	}
	else
		*(size_t *)ptr = 0;
}
