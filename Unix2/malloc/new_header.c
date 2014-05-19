/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharpen <lcharpen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 12:19:29 by lcharpen          #+#    #+#             */
/*   Updated: 2014/04/20 12:38:24 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include "malloc.h"

void	*new_tiny_header(size_t size)
{
	t_block	*block;
	void	*res;

	if (!m_type.tiny.page || m_type.tiny.nb_elem >= 31)
		new_block(size);
	*(size_t *)m_type.tiny.page = size;
	m_type.tiny.page += sizeof(block->size);
	*(void **)m_type.tiny.page = m_type.tiny.page - sizeof(block->size) + N;
	m_type.tiny.page += sizeof(size);
	res = m_type.tiny.page;
	m_type.tiny.page += N - 16;
	m_type.tiny.nb_elem++;
	return (res);
}

void	*new_small_header(size_t size)
{
	t_block	*block;
	void	*res;

	if (!m_type.small.page || m_type.small.nb_elem >= 4)
		new_block(size);
	*(size_t *)m_type.small.page = size;
	m_type.small.page += sizeof(block->size);
	*(void **)m_type.small.page = m_type.small.page - sizeof(block->size) + M;
	m_type.small.page += sizeof(size);
	res = m_type.small.page;
	m_type.small.page += M - 16;
	m_type.small.nb_elem++;
	return (res);
}

void	*new_large_header(size_t size)
{
	t_block	*block;
	void	*res;
	int		len;

	new_block(size);
	len = (size / PAGE + (size % PAGE != 0)) * PAGE;
	*(size_t *)m_type.large.page = size;
	m_type.large.page += sizeof(block->size);
	*(void **)m_type.large.page = m_type.large.page - sizeof(block->size) - len;
	m_type.large.page += sizeof(size);
	res = m_type.large.page;
	return (res);
}
