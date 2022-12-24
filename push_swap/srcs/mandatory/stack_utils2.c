/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:49:54 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 11:56:32 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_block_end(t_s **s, t_s *new)
{
	t_s	*end;
	
	if (!new)
		return ;
	if (!*s || !s)
	{
		*s = new;
		return ;
	}
	end = stack_last(s);
	end->next = new;
}

void	add_block_start(t_s **s, t_s *new)
{
	t_s	*start;
	
	if (!new)
		return ;
	if (!*s || !s)
	{
		*s = new;
		(*s)->next = NULL;
		return ;
	}
	start = *s;
	*s = new;
	(*s)->next = start;
}

void	remove_block(t_s **s)
{
	if (!*s)
		return ;
	if (stack_length(s) == 1)
	{
		*s = NULL;
		return ;
	}
	*s = (*s)->next;	
}