/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:34:11 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/20 12:33:51 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include "malloc.h"

void	*alloc_pages(size_t size)
{
	int *plen;
	int	len;

	len = (size / PAGE + (size % PAGE != 0)) * PAGE;
	plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (plen == MAP_FAILED)
		return (NULL);
	return (plen);
}

void	new_block(size_t size)
{
	if (size <= N - 16)
	{
		m_type.tiny.page = alloc_pages(size);
		m_type.tiny.start = m_type.tiny.page;
		m_type.tiny.nb_elem = 0;
		m_type.tiny.type = 1;
	}
	else if (size <= M - 16)
	{
		m_type.small.page = alloc_pages(size);
		m_type.small.start = m_type.small.page;
		m_type.small.nb_elem = 0;
		m_type.small.type = 2;
	}
	else
	{
		m_type.large.page = alloc_pages(size);
		m_type.large.start = m_type.large.page;
		m_type.large.nb_elem = 0;
		m_type.large.type = 3;
	}
}

void	*add_block(size_t size)
{
	if (size <= N - 16)
		return (new_tiny_header(size));
	else if (size <= M - 16)
		return (new_small_header(size));
	else
		return (new_large_header(size));
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ret;

	ret = add_block(size);
	return (ret);
}
