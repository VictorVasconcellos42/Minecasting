/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_memtools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:01:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 01:22:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

t_mem	*gc_meminit(void)
{
	t_mem	*mem;

	mem = gc_memnew(0, 0);
	return (mem);
}

void	*gc_alloc(void *ptr, char *context, t_mem *mem)
{
	t_mem	*node;

	if (ptr)
	{
		node = gc_memnew(ptr, context);
		if (!node)
		{
			free (ptr);
			return (0);
		}
		gc_memadd_back(&mem, node);
	}
	else
		errno = ENOMEM;
	return (ptr);
}

void	gc_free(void *ptr, t_mem **mem)
{
	t_mem	*aux;
	t_mem	*head;

	if (!mem || !*mem)
		return ;
	head = *mem;
	aux = 0;
	while (*mem)
	{
		if ((**mem).ptr == ptr)
		{
			if (!aux)
				head = (**mem).next;
			else
				aux->next = (**mem).next;
			free ((**mem).ptr);
			free ((**mem).ctx);
			free (*mem);
			break ;
		}
		aux = *mem;
		*mem = (**mem).next;
	}
	*mem = head;
}

void	gc_memdelete(t_mem **mem)
{
	t_mem	*nxt;

	while (*mem)
	{
		nxt = (**mem).next;
		free((**mem).ptr);
		free((**mem).ctx);
		free (*mem);
		*mem = nxt;
	}
}

void	gc_sumary(t_mem *mem)
{
	int	i;

	gc_printf ("\n--------------------| SUMARY |-------------------\n");
	gc_printf ("Blocks allocate'd: %d\n", gc_memsize(mem));
	i = -1;
	while (mem)
	{
		gc_printf ("----------------------------------------\n");
		gc_printf ("block[%d]:\t", ++i);
		gc_printf ("%p ", mem->ptr);
		gc_printf ("[%s]\n", mem->ctx);
		mem = mem->next;
	}
	gc_printf ("--------------------| END |-------------------\n");
}
